#include "day_08/task_2/haunted_wasteland.hpp"
#include "gtest/gtest.h"


class HauntedWasteLandFixture : public ::testing::Test
{
protected:
    const DesertPlan desert_plan{
        {"11A", {"11B", "XXX"}}, {"11B", {"XXX", "11Z"}},
        {"11Z", {"11B", "XXX"}}, {"22A", {"22B", "XXX"}},
        {"22B", {"22C", "22C"}}, {"22C", {"22Z", "22Z"}},
        {"22Z", {"22B", "22B"}}, {"XXX", {"XXX", "XXX"}}};
};


TEST_F(HauntedWasteLandFixture, GivenCurrentPlace_WhenGoLeft_ThenReachExpectedPlace)
{
    std::string current_place{"11A"};
    char direction{'L'};
    std::string expected_place{"11B"};

    EXPECT_EQ(go_to_next_place(desert_plan, current_place, direction), expected_place);
}

TEST_F(HauntedWasteLandFixture, GivenDesertPlan_WhenLookingForStartingPositions_ThenFindThem)
{
    StartPositions expected_all_start_positions{"11A", "22A"};
    auto found_start_positions = found_starting_positions(desert_plan);

    EXPECT_EQ(found_start_positions, expected_all_start_positions);
}

TEST_F(HauntedWasteLandFixture, GivenDesertPlanAndStartingPositions_WhenCountingStepsToXXZ_ThenReceive)
{
    StartPositions start_positions{"11A", "22A"};
    auto expected_nr_steps{6};
    std::string directions{"LR"};

    EXPECT_EQ(count_steps_to_XXZ(desert_plan, start_positions, directions), expected_nr_steps);
}
