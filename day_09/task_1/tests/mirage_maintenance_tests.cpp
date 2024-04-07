#include "day_09/task_1/mirage_maintenance.hpp"
#include "gtest/gtest.h"

TEST(MirageMaintenanceToolsShould, ReturnCalculatedOneStepDifference)
{
    const int depth = 1;
    std::vector<int> report{0, 3, 6, 9, 12, 15};
    std::vector<int> expected_report{3, 3, 3, 3, 3, 0};
    calcucale_one_step_difference(report, depth);

    EXPECT_EQ(report, expected_report);
}

TEST(MirageMaintenanceToolsShould, ReturnCalculatedOneStepDifference1)
{
    const int depth = 2;
    std::vector<int> report{3, 3, 3, 3, 3, 0};
    std::vector<int> expected_report{0, 0, 0, 0, 3, 0};
    calcucale_one_step_difference(report, depth);

    EXPECT_EQ(report, expected_report);
}

TEST(MirageMaintenanceToolsShould, ReturnCalculatedFinalValues)
{
    std::vector<int> report{0, 3, 6, 9, 12, 15};
    std::vector<int> expected_report{0, 0, 0, 0, 3, 0};
    calcucale_final_values(report);

    EXPECT_EQ(report, expected_report);
}

TEST(MirageMaintenanceToolsShould, ReturnCalculatedExtrapolatedValues)
{
    std::vector<int> report{0, 3, 6, 9, 12, 15};
    std::vector<int> expected_extrapolated_values{0, 0, 0, 0, 3, -3};
    calculate_extrapolated_values(report);

    EXPECT_EQ(report, expected_extrapolated_values);
}
