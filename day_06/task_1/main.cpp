#include "boat_race.hpp"
#include "debug_features/debug_features.hpp"
#include "path_helper/path_helper.hpp"
#include <algorithm>
#include <cassert>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

using Time = int;
using Distance = int;

void run_app(std::string filename)
{
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string prefix_word;

    int number_of_expected_entries{4};
    std::vector<Time> times(number_of_expected_entries);
    std::vector<Distance> distances(number_of_expected_entries);
    std::string final_time{};
    std::string final_distance{};


    fs >> prefix_word;
    for(int i = 0; i < number_of_expected_entries; ++i)
        fs >> times[i];

    fs >> prefix_word;
    for(int i = 0; i < number_of_expected_entries; ++i)
        fs >> distances[i];

    for(const auto digits : times)
    {
        final_time += std::to_string(digits);
    }

    for(const auto digits : distances)
    {
        final_distance += std::to_string(digits);
    }

    std::cout << final_time << " " << final_distance << std::endl;

    // int product_of_winning_strategies{1};
    // for(int i = 0; i < number_of_expected_entries; ++i)
    //     product_of_winning_strategies *= count_winning_strategies(times[i], distances[i]);

    std::cout << count_winning_strategies(std::stoll(final_time), std::stoll(final_distance))
              << std::endl;

    fs.close();
}

int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_06/task_1/input"};
    run_app(filename);
    return 0;
}
