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
    run_app();
    // run_tests();
    return 0;
}

void run_tests()
{
    {

    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}
