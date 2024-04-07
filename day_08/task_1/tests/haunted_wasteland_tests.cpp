#include "day_08/task_1/haunted_wasteland.hpp"
#include "gtest/gtest.h"


class HauntedWasteLandFixture : public ::testing::Test
{
protected:
    const DesertPlan desert_plan{{"AAA", {"BBB", "CCC"}},
                                 {"BBB", {"DDD", "EEE"}},
                                 {"CCC", {"ZZZ", "GGG"}},
                                 {"DDD", {"DDD", "DDD"}},
                                 {"EEE", {"EEE", "EEE"}},
                                 {"GGG", {"GGG", "GGG"}},
                                 {"ZZZ", {"ZZZ", "ZZZ"}}};
};

TEST_F(HauntedWasteLandFixture, GivenCurrentPlace_WhenGoLeft_ThenReachExpectedPlace)
{
    std::string current_place{"AAA"};
    char direction{'L'};
    std::string expected_place{"BBB"};

    EXPECT_EQ(go_to_next_place(desert_plan, current_place, direction), expected_place);
}

TEST_F(HauntedWasteLandFixture, GivenCurrentPlanAndDirections_WhenCountStepsToZZZ_ShouldReturnTwo)
{
    std::string current_place{"AAA"};
    std::string directions{"RL"};
    int expected_no_steps{2};

    EXPECT_EQ(count_steps_to_ZZZ(desert_plan, current_place, directions), expected_no_steps);
}
