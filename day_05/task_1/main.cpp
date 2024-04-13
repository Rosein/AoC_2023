#include "debug_features/debug_features.hpp"
#include "path_helper/path_helper.hpp"
#include "seed_planter.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

void run_tests();

void run_app(std::string filename)
{
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;
    // wczytamy seedy
    std::getline(fs, line);
    std::vector<MapRange> seeds;

    {
        std::stringstream seed_stream{line};
        std::string to_ignore;
        seed_stream >> to_ignore;
        MapRange read_seed;
        while(seed_stream >> read_seed)
        {
            seeds.push_back(read_seed);
        }
    }

    std::getline(fs, line); // to ignore new line after seeds

    // receiveing maps
    std::vector<Map> maps;

    constexpr int kExpectedNumberOfMaps{7};
    for(int i = 0; i < kExpectedNumberOfMaps; ++i)
    {
        std::getline(fs, line); // to ignore title of map
        std::string raw_map;
        while(std::getline(fs, line))
        {
            if(!line.empty())
            {
                raw_map += line + " ";
            }
            else
            {
                break;
            }
        }

        maps.push_back(prepare_map_subcharacteristic(raw_map));
    }

    // Finding the smallest location
    std::vector<MapRange> locations;
    for(auto seed : seeds)
    {
        for(const auto& map : maps)
        {
            seed = evaluate_value_of_mapping(seed, map);
        }
        locations.push_back(seed);
    }

    auto it = std::minmax_element(locations.begin(), locations.end());
    if(it.first != locations.end())
    {
        std::cout << "Smallest location is: " << *(it.first) << std::endl;
    }

    fs.close();
}


int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_05/task_1/input"};
    run_app(filename);
    return 0;
}
