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
        auto result = evaluate_value_of_mapping(seed, seed_to_soil_map); 

        assert(evaluate_value_of_mapping(seed, seed_to_soil_map) == 81);
        std::cout << GREEN << " OK" << RESET << std::endl;
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}
