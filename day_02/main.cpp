#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <map>
#include "cube_conundrum.hpp"

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
        assert(is_game_set_possible({{Color::blue, 10},{Color::green, 2}, {Color::red, 6}}));
    }

    {
        assert(!is_game_set_possible({{Color::blue, kMaximalPossibleGameSet[Color::blue] + 1},{Color::green, 2}, {Color::red, 6}}));
    }

    {
        assert(is_game_set_possible({{Color::green, 2}, {Color::red, 6}}));
    }

    {
        assert(is_game_possible("3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"));
    }

    std::cout << "Tests passed!" << std::endl;
}
