#include "hot_springs.hpp"
#include "path_helper/path_helper.hpp"
#include <fstream>
#include <iostream>
#include <string>

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
    std::vector<std::string> lines;

    while(std::getline(fs, line))
    {
        std::cout << line << std::endl;
        lines.push_back(line);
    }

    long long unsigned int total_distance{0};

    for(auto line : lines)
    {
        total_distance += arrange_spring(extract_conditions(line), extract_groups(line));
    }

    std::cout << "Total distance: " << total_distance << std::endl;
    fs.close();
}

int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_12/task_1/input"};
    run_app(filename);
    return 0;
}
