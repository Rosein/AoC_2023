#include "debug_features/debug_features.hpp"
#include "seed_planter.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <thread>

void run_tests();

void find_lowest_location_in_seed_pack(std::pair<MapRange, MapRange> seeds,
                                       const std::vector<Map>& maps,
                                       MapRange& lowest_location)
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
    std::string filename{
        "/home/rkumanek/Repos/AoC_2023/day_05/task_2/input_example"};
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
    std::vector<MapRange> locations(seeds_pack.size(),
                                    std::numeric_limits<MapRange>::max());
    std::vector<std::thread> threads;
    for(auto i = 0U; i < seeds_pack.size(); ++i)
    {
        auto t = std::thread(find_lowest_location_in_seed_pack, seeds_pack[i],
                             std::ref(maps), std::ref(locations[i]));
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
    return 0;
}
