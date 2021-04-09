#include "automata/nfa.hh"

#include <stack>
#include <algorithm>
#include <iostream>

namespace final_project::automata
{
    inline bool is_operator(char c)
    { 
        return (c == '|') || (c == '?') || (c =='*');
    }

    nfa build_nfa(const std::vector<char>& regex)
    {
        std::stack<nfa> nfa_stack;
        for(size_t i = 0; i < regex.size(); ++i)
        {
            char c = regex[i];
            if (!is_operator(c))
            {
                if(c == '\\') //Recognize escaped characters
                    c = regex[++i];
                std::set<char> alphabet;
                alphabet.insert(c);
                nfa n = {alphabet, {1}, {{{c, {1}}}}};
                nfa_stack.push(n);
            }
            else if (c == '?')
            {
                nfa n2 = nfa_stack.top();
                nfa_stack.pop();
                nfa n1 = nfa_stack.top();
                nfa_stack.pop();

                auto n1_table = n1._M_transitions;
                //Re-number states
                n2.renumber(n1._M_transitions.size());
                auto n2_table = n2._M_transitions;
                //Merge tables
                for(const auto& transition: n2_table)
                    n1_table.push_back(transition);
                std::vector<state_t> accepting_state = n2._M_accepting_states;
                //Concatenate alphabets
                std::set<char> merged_alphabet;
                std::set_union(n1._M_alphabet.begin(), n1._M_alphabet.end(),
                               n2._M_alphabet.begin(), n2._M_alphabet.end(),
                               std::inserter(merged_alphabet, merged_alphabet.end()));
                n1._M_transitions = n1_table;
                n1._M_alphabet = merged_alphabet;
                n1._M_accepting_states = accepting_state;
                nfa_stack.push(n1);
            } 
            else if (c == '|')
            {
                nfa n2 = nfa_stack.top();
                nfa_stack.pop();
                nfa n1 = nfa_stack.top();
                nfa_stack.pop();

                n1.renumber(1);
                n2.renumber(1 + n1._M_transitions.size() + 1);
                //Create new accepting state
                state_t accepting_state = 1 + n1._M_transitions.size() + 1 + n2._M_transitions.size() + 1;
                //Add transition to accepting state 
                n1._M_transitions.push_back({{EPSILON, {accepting_state}}});
                n2._M_transitions.push_back({{EPSILON, {accepting_state}}});
                nfa::table_t new_table;
                //Create new start state with epsilon transitions to NFAs to be merged
                new_table.push_back({{EPSILON, {1, 1 + static_cast<int>(n1._M_transitions.size())}}});
                //Add NFAs to merged NFA
                for(const auto& row: n1._M_transitions)
                {
                    new_table.push_back(row);
                }
                for(const auto& row: n2._M_transitions)
                {
                    new_table.push_back(row);
                }
                //Merge alphabets
                std::set<char> merged_alphabet;
                std::set_union(n1._M_alphabet.begin(), n1._M_alphabet.end(),
                               n2._M_alphabet.begin(), n2._M_alphabet.end(),
                               std::inserter(merged_alphabet, merged_alphabet.end()));
                //Create NFA
                std::vector<state_t> accepting_states = {accepting_state};
                nfa merged = {merged_alphabet, accepting_states, new_table};
                nfa_stack.push(merged);
            } else if (c == '*')
            {
                nfa n = nfa_stack.top();
                nfa_stack.pop();
                //Add transition back to start state
                n._M_transitions.push_back({{EPSILON, {0}}});
                //Re-number states
                n.renumber(1);
                //Create accepting states
                state_t accepting_state = n._M_transitions.size() + 1;
                //Add transition to accepting state
                n._M_transitions.back()[EPSILON].push_back(accepting_state);
                //Create new start state
                nfa::table_t new_table;
                new_table.push_back({{EPSILON, {1, accepting_state}}});
                for(const auto& row: n._M_transitions)
                    new_table.push_back(row);
                nfa merged{n._M_alphabet, {accepting_state}, new_table};
                nfa_stack.push(merged);
            }
        }
        return nfa_stack.top();
    }

    nfa build_nfa(const std::vector<std::vector<char>>& regex)
    {
        nfa n;
        for(const auto& r: regex)
        {
            nfa subunit = build_nfa(r);
            if(n._M_transitions.empty())
            {
                n._M_transitions = subunit._M_transitions;
                n._M_accepting_states = subunit._M_accepting_states;
                n._M_alphabet = subunit._M_alphabet;
            }
            else 
            {
                subunit.renumber(n._M_transitions.size());
                for(const auto state: subunit._M_accepting_states)
                    n._M_accepting_states.push_back(state);
                for(const auto& row : subunit._M_transitions)
                    n._M_transitions.push_back(std::move(row));
                std::set<char> merged_alphabet;
                std::set_union(n._M_alphabet.begin(), n._M_alphabet.end(),
                               subunit._M_alphabet.begin(), subunit._M_alphabet.end(),
                               std::inserter(merged_alphabet, merged_alphabet.end()));
                n._M_alphabet = merged_alphabet;
            }
        }
        return n;
    }
}

#include <iostream>

std::ostream& operator<<(std::ostream& os, const final_project::automata::nfa& n)
    {
        os << "Alphabet: {";
        auto it = n._M_alphabet.begin();
        for(; std::distance(it, n._M_alphabet.end()) > 1; ++it)
            os << *it << ", ";
        os << *(n._M_alphabet.rbegin()) << "}";
        os << "\nAccepting states: {";
        for(size_t i = 0; i < n._M_accepting_states.size() - 1; ++i)
            os << n._M_accepting_states[i] << ", ";
        os << n._M_accepting_states.back() << "}";
        os << "\nTransition table: \n";
        for(const auto& row: n._M_transitions)
        {
            for(const auto& state: row)
            {
                char c = state.first;
                if (c == final_project::automata::EPSILON)
                    os << "\t{epsilon, {";
                else
                    os << "\t{" << c << ", {";
                for(size_t i = 0; i < state.second.size() -1; ++i)
                    os << state.second[i] << ", ";
                os << state.second.back() << "}}";
            }
            os << "\n";
        }
        return os;
    }