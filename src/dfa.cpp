#include "automata/dfa.hh"

#include <unordered_set>
#include <algorithm>

namespace final_project
{
    namespace automata
    {
        //Compute the epsilon closure of a state (all of the states that can be reached
        //with e-moves from the current state).
        std::set<state_t> epsilon_closure(state_t start, const nfa::table_t& transitions)
        {
            std::set<state_t> closure;
            std::set<state_t> work_list;

            closure.insert(start);
            work_list.insert(start);

            while(!work_list.empty())
            {
                state_t n = *work_list.begin();
                work_list.erase(work_list.begin());
                std::set<state_t> t;

                auto state = transitions[n];
                //Find all states that can be reach with one e-move from current state
                for(const auto& transition: state)
                {
                    if(transition.first == EPSILON)
                    {
                        //For each of the states that can be reached with an e-move, 
                        //find all the states that can be reached with an e-move from that state 
                        //and add them to closure
                        auto new_states = transition.second;
                        for(auto& new_state: new_states)
                        {
                           auto sub_closure = epsilon_closure(new_state, transitions);
                           std::set<state_t> merged;
                           std::set_union(t.begin(), t.end(),
                                          sub_closure.begin(), sub_closure.end(),
                                          std::inserter(merged, merged.end()));
                            t = merged;
                        }
                    }
                }
                //Add found states to closure
                closure = t;
                //Add states to work list
                for(auto state: t)
                    work_list.insert(state);
            }
            //Return the epsilon closure
            return closure;
        }

        dfa<char> powerset_construction(const nfa& n)
        {
            const auto& accepting_states = n._M_accepting_states;
            const auto& transition_table = n._M_transitions;
            //Perform epsilon closure of initial state
            auto q0 = epsilon_closure(0, transition_table);
            //Initialize variables
            std::vector<std::set<state_t>> Q = {q0};
            std::vector<std::set<state_t>> work_list = {q0};
            std::unordered_map<std::set<state_t>, std::unordered_map<char, std::set<state_t>>> T;
            const std::set<char>& alphabet = n._M_alphabet;

            while(!work_list.empty())
            {
                auto q_i = work_list.back();
                work_list.pop_back();
                //Loop over each character in the alphabet
                for(auto c: alphabet)
                {
                    std::set<state_t> t;
                    //Loop over each state in the current NFA configuration
                    for(auto curr_state: q_i)
                    {
                        const auto& row = transition_table[curr_state];
                        //Check if there is a trnsition on this character
                        auto it = row.find(c);
                        if (it != row.end())
                        {
                            //Get states that can be transition to
                            auto new_states = it->second;
                            //Compute epsilon closure of each state 
                            for(auto new_state: new_states)
                            {
                                auto e_closure = epsilon_closure(new_state, transition_table);
                                for(auto e_state: e_closure)
                                    t.insert(e_state);
                            }
                        }
                    }
                    auto it2 = std::find_if(Q.begin(), Q.end(), [&](const std::set<final_project::automata::state_t>& curr)
                        {
                            return std::equal(t.begin(), t.end(), curr.begin(), curr.end());
                        });
                    //We don't already have this state
                    if(it2 == Q.end()) {
                        Q.push_back(t);
                        work_list.push_back(t);
                    }
                }
            }

            //Convert Q and T to DFA
            std::vector<state_t> dfa_accepting_states;
            dfa<char>::table_t dfa_transitions;

            //If any set of states in Q has an accepting state, 
            //that state becomes an accetping state in D
            for(size_t i = 0; i < Q.size(); ++i)
            {
                auto states = Q[i];
                auto it = std::find_first_of(states.begin(), states.end(), accepting_states.begin(), accepting_states.end());
                if (it != states.end())
                    dfa_accepting_states.push_back(i);
                
                std::unordered_map<char, state_t> row;
                auto T_row = T[states];
            }
        }
    } // namespace automata
    
} // namespace final_project
