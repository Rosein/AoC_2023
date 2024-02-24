#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "boat_race.hpp"
#include "../../debug_features.hpp"

using Time = int;
using Distance = int;

void run_tests();

void run_app()
{
    std::string filename{"input"};
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

    std::cout << count_winning_strategies(std::stoll(final_time), std::stoll(final_distance)) << std::endl;

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
        DEBUG_PRINT_TESTNAME("Test is_loading_time_enough_to_win() #1:");
        long long int  time{7};
        long long int  distance{9};
        long long int  loading_time{3};

        assert(is_loading_time_enough_to_win(time, distance, loading_time));
    }

    {
        DEBUG_PRINT_TESTNAME("Test find_the_shortest_loading_time_to_win() #1:");
        long long int  time{7};
        long long int  distance{9};
        long long int  expected_loading_time{2};

        assert(find_the_shortest_loading_time_to_win(time, distance) == expected_loading_time);
    }

    {
        DEBUG_PRINT_TESTNAME("Test find_the_longest_loading_time_to_win() #1:");
        long long int  time{7};
        long long int  distance{9};
        long long int  expected_loading_time{5};

        assert(find_the_longest_loading_time_to_win(time, distance) == expected_loading_time);
    }

    {
        DEBUG_PRINT_TESTNAME("Test count_winning_strategies() #1:");
        long long int  time{7};
        long long int  distance{9};
        long long int  expected_winning_options{4};

        assert(count_winning_strategies(time, distance) == expected_winning_options);
    }

    {
        DEBUG_PRINT_TESTNAME("Test count_winning_strategies() #2:");
        long long int  time{15};
        long long int  distance{40};
        long long int  expected_winning_options{8};

        assert(count_winning_strategies(time, distance) == expected_winning_options);
    }

    {
        DEBUG_PRINT_TESTNAME("Test count_winning_strategies() #3:");
        long long int  time{30};
        long long int  distance{200};
        long long int  expected_winning_options{9};

        assert(count_winning_strategies(time, distance) == expected_winning_options);
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}
