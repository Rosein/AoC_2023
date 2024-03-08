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
    std::string filename{"input_example"};
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

    std::cout << count_steps_to_ZZZ(desert_plan, "AAA", directions) << std::endl;

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
    const DesertPlan desert_plan {
        {"11A",{"11B", "XXX"}},
        {"11B",{"XXX", "11Z"}},
        {"11Z",{"11B", "XXX"}},
        {"22A",{"22B", "XXX"}},
        {"22B",{"22C", "22C"}},
        {"22C",{"22Z", "22Z"}},
        {"22Z",{"22B", "22B"}},
        {"XXX",{"XXX", "XXX"}}};

    {
        DEBUG_PRINT_TESTNAME("Test go_to_next_place() #1: GivenCurrentPlace_WhenGoLeft_ThenReachExpectedPlace");
        std::string current_place{"11A"};
        char direction{'L'};
        std::string expected_place{"11B"};

        assert(go_to_next_place(desert_plan, current_place, direction) == expected_place);
    }

    {
        DEBUG_PRINT_TESTNAME("Test found_starting_positions() #1: GivenDesertPlan_WhenLookingForStartingPositions_ThenFindThem");
        StartPositions expected_all_start_positions{"11A", "22A"};
        auto found_start_positions = found_starting_positions(desert_plan);

        assert(found_start_positions == expected_all_start_positions);
    }

    {
        DEBUG_PRINT_TESTNAME("Test count_steps_to_XXZ() #1: GivenDesertPlanAndStartingPositions_WhenCountingStepsToXXZ_ThenReceive");
        StartPositions start_positions{"11A", "22A"};
        auto expected_nr_steps{6};
        std::string directions{"LR"};

        assert(count_steps_to_XXZ(desert_plan, start_positions, directions) == expected_nr_steps);
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}
