#include "lexer.hh"
#include <iostream>

int main(int argc, char** argv)
{
    std::string l;
    while (true) {
        std::cout << "Enter text to lexer or type Q to quit: \n";
        std::string text;
        getline(std::cin, text);
        if (text == "Q")
            break;
        lexer::lexer l(text);
        auto tokens = l.tokenize();
        for(auto tok: tokens)
        {
            std::cout << tok._M_val << " ";
        }
        std::cout << std::endl << std::endl;
    }
    return 0;
}