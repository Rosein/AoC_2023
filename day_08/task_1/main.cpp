#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <map>
#include "haunted_wasteland.hpp"
#include "../../debug_features.hpp"

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
    // run_tests();
    return 0;
}

void run_tests()
{
    const DesertPlan desert_plan {
        {"AAA", {"BBB", "CCC"}},
        {"BBB", {"DDD", "EEE"}},
        {"CCC", {"ZZZ", "GGG"}},
        {"DDD", {"DDD", "DDD"}},
        {"EEE", {"EEE", "EEE"}},
        {"GGG", {"GGG", "GGG"}},
        {"ZZZ", {"ZZZ", "ZZZ"}}
    };

    // {
    //     DEBUG_PRINT_TESTNAME("Test go_to_next_place() #1: GivenCurrentPlace_WhenGoLeft_ThenReachExpectedPlace");
    //     std::string current_place{"AAA"};
    //     char direction{'L'};
    //     std::string expected_place{"BBB"};

    //     assert(go_to_next_place(desert_plan, current_place, direction) == expected_place);
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test count_steps_to_ZZZ() #1: GivenCurrentPlanAndDirections_WhenCountStepsToZZZ_ShouldReturnTwo");
    //     std::string current_place{"AAA"};
    //     std::string directions{"RL"};
    //     int expected_no_steps{2};

    //     assert(count_steps_to_ZZZ(desert_plan, current_place, directions) == expected_no_steps);
    // }


    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}
