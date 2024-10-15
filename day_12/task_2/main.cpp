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

    long long unsigned total_distance{0};

    for(auto line : lines)
    {
        std::vector<int> groups = extract_groups(line);
        std::string conditions = extract_conditions(line);
        unfold_data(conditions, groups);

        std::cout <<  conditions << std::endl;
        conditions = "." + conditions + ".";

        total_distance += arrange_spring(conditions, groups);
    }

    std::cout << "Total distance: " << total_distance << std::endl;
    fs.close();
}

int main(int argc, char** argv)
{
    std::string filename = std::string{"/Users/dariakumanek/Desktop/workspace/projects/AoC_2023/day_12/task_2/input"};
    run_app(filename);
    return 0;
}
