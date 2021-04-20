#include "automata/regex_parser.hh"
#include "exception/exceptions.hh"

#include <stdexcept>
#include <stack>
#include <regex>

namespace final_project
{
    namespace regex 
    {
    regex_parser::regex_parser(std::istream& in) noexcept
        : _M_in(in)
    {

    }

    std::vector<std::pair<std::string, std::vector<char>>> regex_parser::parse()
    {
        if(!_M_in.good())
            throw std::range_error("Input stream is in invalid state.");
        std::string line;
        std::vector<std::pair<std::string, std::vector<char>>> regex;
        while(getline(_M_in, line))
        {   
            size_t colon_index = line.find(":");
            std::string label = line.substr(0, colon_index);
            std::string r = line.substr(line.rfind(" ") + 1);
            regex.push_back(std::make_pair(label, parse_regex(r)));
        }
        return regex;
    }

    std::vector<char> regex_parser::parse_regex(std::string& regex)
    {
        preprocess(regex);
        std::vector<char> postfix;
        std::stack<char> op_stack;
        for(size_t i = 0; i < regex.size(); ++i)
        {
            char c = regex[i];
            if(!is_operator(c) && c != '(' && c != ')')
            {
                postfix.push_back(c);
                if(c == '\\')
                {
                    if (i == regex.length() - 1 
                        && regex[i + 1] != '*' 
                        && regex[i + 1] != '|' 
                        && regex[i + 1] != '\\'
                        && regex[i + 1] != '?')
                        throw exceptions::invalid_regex_exception("Incomplate escape character sequence");
                    postfix.push_back(regex[++i]);
                }
            }
            else if(c == '(')
                op_stack.push(c);
            else if (c == ')')
            {
                while(!op_stack.empty() && op_stack.top() != '(')
                {
                    postfix.push_back(op_stack.top());
                    op_stack.pop();
                }
                op_stack.pop();
            }
            else 
            {
                while(!op_stack.empty() && precedence(c) <= precedence(op_stack.top()))
                {
                    postfix.push_back(op_stack.top());
                    op_stack.pop();
                }
                op_stack.push(c);
            }
        }
        while(!op_stack.empty())
        {
            postfix.push_back(op_stack.top());
            op_stack.pop();
        }
        return postfix;
    }

    void regex_parser::preprocess(std::string& regex)
    {
        //Replace [0-9]
        std::regex digit_regex("\\[0-9\\]");
        std::string digit_replacement = "(0|1|2|3|4|5|6|7|8|9)";
        std::string digits_added;
        std::regex_replace(std::back_inserter(digits_added), regex.begin(), regex.end(), digit_regex, digit_replacement);
        //Replace [a-z]
        std::regex lower_regex("\\[a-z\\]");
        std::string lower_replacement = "(a|b|c|d|e|f|g|h|i|j|k|l|m|n|o|p|q|r|s|t|u|v|w|x|y|z)";
        std::string lower_added;
        std::regex_replace(std::back_inserter(lower_added), digits_added.begin(), digits_added.end(), lower_regex, lower_replacement);
        //Replace [A-Z]
        std::regex upper_regex("\\[A-Z\\]");
        std::string upper_replacement = "(A|B|C|D|E|F|G|H|I|J|K|L|M|N|O|P|Q|R|S|T|U|V|W|X|Y|Z)";
        std::string upper_added;
        std::regex_replace(std::back_inserter(upper_added), lower_added.begin(), lower_added.end(), upper_regex, upper_replacement);
        //Replace [A-Za-z]
        std::regex all_regex("\\[A-Za-z\\]");
        std::string all_replacement = lower_replacement.substr(0, lower_replacement.size() - 1);
        all_replacement += "|" + upper_replacement.substr(1);
        std::string all_replaced;
        std::regex_replace(std::back_inserter(all_replaced),upper_added.begin(), upper_added.end(), all_regex, all_replacement);
        //Add concatenation operator
        //Cases where concatentation operator should be inserted 
        //  1. Between two tokens e.g. ab -> a?b
        //  2. Between token and ( e.g. a(ab) -> a?(a?b)
        //  3. Between * and token e.g. a*b -> a*?b 
        //  4. Between * and ( e.g a*(ab) -> a*?(a?b)
        //  5. Between ) and token e.g. a(ab)c -> a?(a?b)?c
        //  6. Between ) and ( e.g. a(ab)(c)->a?(a?b)?(c)
        for(size_t i = 0; i < all_replaced.length() -1; ++i)
        {
            if(all_replaced[i] == ')')
            {
                if(all_replaced[i+1] == '(' || (!is_operator(all_replaced[i+1]) && all_replaced[i+1] != ')'))
                {
                    all_replaced.insert(i+1,"?");
                    ++i;
                }
            }
            else if (all_replaced[i] == '\\')
            {
                ++i;
                if (i == all_replaced.length() - 1)
                    break;
                if(all_replaced[i+1] == '(' || (!is_operator(all_replaced[i+1]) && all_replaced[i+1] != ')'))
                {
                    all_replaced.insert(i+1,"?");
                    ++i;
                }
            }
            else if(all_replaced[i] == '*')
            {
                if(all_replaced[i+1] == '*') //Expression of form a** which isn't allowed
                    throw exceptions::invalid_regex_exception("Unexpcted token: *");
                if(all_replaced[i+1] == '(' || (!is_operator(all_replaced[i+1]) && all_replaced[i+1] != ')'))
                {
                    all_replaced.insert(i+1,"?");
                    ++i;
                }
            }
            else if(all_replaced[i] != '|' && all_replaced[i] != '(')
            {
                if(all_replaced[i+1] == '(' || (!is_operator(all_replaced[i+1]) && all_replaced[i+1] != ')'))
                {
                    all_replaced.insert(i+1,"?");
                    ++i;
                }
            }
        }
        regex = all_replaced;
    }
    }
} // namespace final_project::regex
