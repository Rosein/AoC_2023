#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "seed_planter.hpp"
#include "../debug_features.hpp"

void run_tests();

void run_app()
{
    std::string filename{"input_example"};
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;
    while(std::getline(fs, line))
    {
        std::cout << line << std::endl;
    }

    fs.close();
}


int main()
{
    // run_app();
    run_tests();
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
        std::cout << GREEN << " OK" << RESET << std::endl;
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
        std::cout << GREEN << " OK" << RESET << std::endl;
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
        std::cout << GREEN << " OK" << RESET << std::endl;
    }

    {
        DEBUG_PRINT_TESTNAME("Test evaluate_value_of_mapping() #4:");
        auto water_to_light = std::vector<MapSubcharacterisctic>{
            {88, 18, 7},
            {18, 25, 70}
        };

        int water{81};

        assert(evaluate_value_of_mapping(water, water_to_light) == 74);
        std::cout << GREEN << " OK" << RESET << std::endl;
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
        std::cout << GREEN << " OK" << RESET << std::endl;
    }

    {
        DEBUG_PRINT_TESTNAME("Test prepare_map_subcharacteristic() #1:");
        std::string raw_data = {"2122609492 2788703865 117293332"
                               "751770532 1940296486 410787026"};

        std::vector<MapSubcharacterisctic> expected_prepared_data = { {2122609492, 2788703865, 117293332},
                                                                      {751770532, 1940296486, 410787026}};

        assert(prepare_map_subcharacteristic(raw_data) == expected_prepared_data);

        std::cout << GREEN << " OK" << RESET << std::endl;
    }



    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}
