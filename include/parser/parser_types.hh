#ifndef PARSER_TYPES_H
#define PARSER_TYPES_H 1

#include <string>
#include <vector>

namespace final_project
{
    namespace parser
    {
        //A strut to represent a rule in the parser grammar
        struct rule_t
        {
            std::string _M_lhs;
            std::vector<std::string> _M_rhs;
            std::vector<std::string> _M_node_types;
        };
    } // namespace parser
    
} // namespace final_project


#endif