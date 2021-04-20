#ifndef ITEM_SET_HH
#define ITEM_SET_HH

#include <set>
#include <string>
#include <vector>

#include "parser_types.hh"

namespace final_project
{
    namespace parser
    {
        struct item_set_t
        {
            size_t _M_pointer;
            std::set<rule_t> _M_rules;
        };

        //Creates item sets from the specified context free grammar. Each item set 
        //is a collection of rules that have been augmented with a "pointer" pointing 
        //to the current position in the rule (the pointer represents the next character
        //to be read).
        //
        //@param rules a vector contianing the rules of the context free grammar 
        //@return a set containing all of the item sets from the rule 
        std::vector<item_set_t> create_item_sets(const std::vector<rule_t>& rules);
    } // namespace parser
   
} // namespace final_project


#endif