#include "debug_features/debug_features.hpp"
#include "haunted_wasteland.hpp"
#include "path_helper/path_helper.hpp"
#include <algorithm>
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

    std::string directions;
    std::string step;
    std::string left_option;
    std::string right_option;
    char to_ignore;

    int desired_length{3};

    DesertPlan desert_plan{};

    fs >> directions;

    while(fs >> step >> to_ignore >> to_ignore >> left_option >> right_option)
    {
        left_option.resize(desired_length);
        right_option.resize(desired_length);
        desert_plan[step] = {left_option, right_option};
    }
    std::cout
        << count_steps_to_XXZ(desert_plan, found_starting_positions(desert_plan), directions)
        << std::endl;

    fs.close();
}


int main(int argc, char** argv)
{
    std::string filename = path_helper::prename +
        std::string{"/AoC_2023/day_08/task_2/input_example"};
    run_app(filename);
    return 0;
}
