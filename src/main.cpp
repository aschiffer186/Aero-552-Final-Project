#include "lexer/lexer_generator.hh"
#include "parser/parser_generator.hh"

#include <iostream>
#include <fstream>

void generate_lexer(const char* filename)
{
    final_project::lexer::generate_lexer(filename);
}

void generate_parser_tables()
{
    std::cout << "Enter filename with context free grammar for parser: " << std::endl;
    std::string filename;
    std::cin >> filename;
    std::ifstream fin(filename.c_str());
    while(!fin.is_open())
    {
        std::cout << "Error opening file. Enter new filename or type Q to quit: ";
        std::cin >> filename;
        if(filename == "Q")
            return;
        fin.close();
        fin.open(filename.c_str());
    }
    final_project::parser::parser_generator pg(fin);
}

int main(int argc, char** argv)
{
    std::cout << "Select option:\n[1] Generate Lexer\n[2] Generate Parser Tables" << std::endl;
    generate_lexer(argv[1]);
}