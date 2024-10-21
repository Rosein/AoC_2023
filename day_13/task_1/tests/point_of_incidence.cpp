#include "day_13/task_1/point_of_incidence.hpp"
#include "gtest/gtest.h"

using GridOfReflections = std::tuple<Grid, bool, int>;

struct IfRefectionTests : ::testing::TestWithParam<GridOfReflections>
{
};

std::vector<GridOfReflections> GenerateReflectionGridParams()
{
    return {
        {
            {
                "##......#",
                "##......#"
            }, true, 0
        },
        {
            {
                "##...#..#",
                "##......#"
            }, false, 0
        },
        {
            {
                "..#.##.#.",
                "##......#",
                "##......#",
                "..#.##.#."
            }, true, 1
        },
        {
            {
                "..#.##.#.",
                "##......#",
                "##..#...#",
                "..#.##.#."
            }, false, 1
        }
        };
}

TEST_P(IfRefectionTests, whenReflectsShouldBeTheSameInUpperAndLowerDirection)
{
    //Given
    auto [grid_to_check, is_reflection, start_index] = GetParam();

    //When
    bool reflect_result = reflects(grid_to_check, start_index);

    //Then
    ASSERT_EQ(reflect_result, is_reflection);
}

INSTANTIATE_TEST_SUITE_P(ReflectionTest, IfRefectionTests, testing::ValuesIn(GenerateReflectionGridParams()));
