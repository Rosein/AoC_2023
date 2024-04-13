#include "cube_conundrum.hpp"
#include "path_helper/path_helper.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

void run_app(std::string filename)
{
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;
    int sum{};

    while(std::getline(fs, line))
    {
        sum += v2::validate_game_result(line);
    }

    std::cout << sum << std::endl;
    fs.close();
}

int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_02/input"};
    run_app(filename);
    return 0;
}
