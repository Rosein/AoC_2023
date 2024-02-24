#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <limits>
#include <thread>
#include "seed_planter.hpp"
#include "../../debug_features.hpp"

void run_tests();

void find_lowest_location_in_seed_pack(std::pair<MapRange, MapRange> seeds, const std::vector<Map>& maps,   MapRange& lowest_location)
{
        MapRange current_seed = seeds.first;

        while(current_seed < seeds.first + seeds.second)
        {
            MapRange current_location{current_seed};

            for(const auto& map : maps)
            {
                current_location = evaluate_value_of_mapping(current_location, map);
            }
            
            if(lowest_location > current_location)
            {
                lowest_location = current_location;
            }
            current_seed++;
        }
}

void run_app()
{
    std::string filename{"input"};
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;
    // wczytamy seedy
    std::getline(fs, line);
    std::vector<std::pair<MapRange, MapRange>> seeds_pack;

    {
        std::stringstream seed_stream{line};
        std::string to_ignore;
        seed_stream >> to_ignore;
        MapRange read_seed;
        MapRange seed_range;
        while(seed_stream >> read_seed >> seed_range)
        {
            seeds_pack.emplace_back(read_seed, seed_range);
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
    std::vector<MapRange> locations(seeds_pack.size(), std::numeric_limits<MapRange>::max());
    int k{};
    std::vector<std::thread> threads;
    for(auto i = 0; i < seeds_pack.size(); ++i)
    {
        auto t = std::thread(find_lowest_location_in_seed_pack, seeds_pack[i], std::ref(maps), std::ref(locations[i]));
        std::cout << "Thread nr " << i << " was started" << std::endl;
        threads.push_back(std::move(t));
    }
    
    for(auto& t : threads)
    {
        t.join();
    }

    // za tą linią już obliczenia się skończyły

    MapRange the_lowerst_location{std::numeric_limits<MapRange>::max()};
    for(auto location : locations)
    {
            if(the_lowerst_location > location)
            {
                the_lowerst_location = location;
            }
    }

    std::cout << "Smallest location is: " << the_lowerst_location << std::endl;

    fs.close();
}


int main()
{
    run_app();
    // run_tests();
    return 0;
}

void run_tests()
{
    {
        DEBUG_PRINT_TESTNAME("Test evaluate_value_of_mapping() #1:");
        auto seed_to_soil_map = std::vector<MapSubcharacterisctic>{
            {50, 98, 2},
            {52, 50, 48},
        };

        int seed{79};

        assert(evaluate_value_of_mapping(seed, seed_to_soil_map) == 81);

    }

    {
        DEBUG_PRINT_TESTNAME("Test evaluate_value_of_mapping() #2:");
        auto soil_to_fertilizer = std::vector<MapSubcharacterisctic>{
            {0, 15, 37},
            {37, 52, 2},
            {39, 0, 15}
        };

        int soil{81};

        assert(evaluate_value_of_mapping(soil, soil_to_fertilizer) == 81);

    }

    {
        DEBUG_PRINT_TESTNAME("Test evaluate_value_of_mapping() #3:");
        auto fertilizer_to_water = std::vector<MapSubcharacterisctic>{
            {49, 53, 8},
            {0, 11, 42},
            {42, 0, 7},
            {57, 7, 4}
        };

        int fertilizer{81};

        assert(evaluate_value_of_mapping(fertilizer, fertilizer_to_water) == 81);

    }

    {
        DEBUG_PRINT_TESTNAME("Test evaluate_value_of_mapping() #4:");
        auto water_to_light = std::vector<MapSubcharacterisctic>{
            {88, 18, 7},
            {18, 25, 70}
        };

        int water{81};

        assert(evaluate_value_of_mapping(water, water_to_light) == 74);

    }

    {
        DEBUG_PRINT_TESTNAME("Test evaluate_value_of_mapping() #5:");
        auto light_to_temperature = std::vector<MapSubcharacterisctic>{
            {45, 77, 23},
            {81, 45, 19},
            {68, 64, 13}
        };

        int light{74};

        assert(evaluate_value_of_mapping(light, light_to_temperature) == 78);
    }

    {
        DEBUG_PRINT_TESTNAME("Test prepare_map_subcharacteristic() #1:");
        std::string raw_data = {"2122609492 2788703865 117293332 "
                                "751770532 1940296486 410787026"};

        std::vector<MapSubcharacterisctic> expected_prepared_data = { {2122609492, 2788703865, 117293332},
                                                                      {751770532, 1940296486, 410787026}};

        assert(prepare_map_subcharacteristic(raw_data) == expected_prepared_data);
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}
