#include "seed_planter.hpp"
#include "debug_features/debug_features.hpp"
#include <sstream>

MapRange evaluate_value_of_mapping(MapRange input_to_evaluate,
                                   std::vector<MapSubcharacterisctic> map_to_evaluate)
{
    for(const auto& el : map_to_evaluate)
    {
        if(input_to_evaluate >= std::get<kSourceStart>(el) and
           input_to_evaluate <=
               (std::get<kSourceStart>(el) + std::get<kRangeLenght>(el) - 1))
        {
            return std::get<kDestinationStart>(el) + input_to_evaluate -
                std::get<kSourceStart>(el);
        }
    }

    return input_to_evaluate;
}

std::vector<MapSubcharacterisctic> prepare_map_subcharacteristic(std::string raw_map)
{
    std::stringstream ss{raw_map};
    std::vector<MapSubcharacterisctic> final_map{};

    MapSubcharacterisctic candi{};
    // DEBUG_PRINT(raw_map);
    while(ss >> std::get<kDestinationStart>(candi) >>
          std::get<kSourceStart>(candi) >> std::get<kRangeLenght>(candi))
    {
        // DEBUG_PRINT(std::get<kDestinationStart>(candi) << " " << std::get<kSourceStart>(candi) << " " << std::get<kRangeLenght>(candi));
        final_map.push_back(candi);
    }

    return final_map;
}
