#include "seed_planter.hpp"

int evaluate_value_of_mapping(int input_to_evaluate, std::vector<MapSubcharacterisctic> map_to_evaluate)
{
    for(const auto el : map_to_evaluate)
    {
        if(input_to_evaluate >= std::get<kSourceStart>(el) 
           and input_to_evaluate<=(std::get<kSourceStart>(el) + std::get<kRangeLenght>(el) - 1 ))
        {
            return std::get<kDestinationStart>(el) + input_to_evaluate - std::get<kSourceStart>(el) ; 
        }
    }

    return input_to_evaluate;
}