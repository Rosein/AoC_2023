#include "debug_features/debug_features.hpp"
#include "haunted_wasteland.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

void run_app()
{
    std::string filename{"/home/rkumanek/Repos/AoC_2023/day_08/task_1/input"};
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

    std::cout << count_steps_to_ZZZ(desert_plan, "VCA", directions) << std::endl;

    fs.close();
}


int main()
{
    run_app();
    return 0;
}
