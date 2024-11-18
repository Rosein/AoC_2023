#include "day_13/task_2/point_of_incidence.hpp"
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


using GridOfSplitedReflections = std::tuple<Grid, int>;

struct FindSplitTests : ::testing::TestWithParam<GridOfSplitedReflections>
{
};

std::vector<GridOfSplitedReflections> GenerateFindSplitParams()
{
    return {
        {
            {
                "##......#",
                "##......#"
            }, 1
        },
        {
            {
                "##...#..#",
                "##......#"
            }, 0
        },
        {
            {
                "..#.##.#.",
                "##......#",
                "##......#",
                "..#.##.#."
            }, 2
        },
        {
            {
                "..#.##.#.",
                "##......#",
                "##..#...#",
                "..#.##.#."
            }, 0
        },
        {
            {
                "#...##..#",
                "#....#..#",
                "..##..###",
                "#####.##.",
                "#####.##.",
                "..##..###",
                "#....#..#"
            }, 4
        },
        {
            {
                "#....#..#",
                "..##..###",
                "#####.##.",
                "#####.##.",
                "..##..###",
                "#....#..#"
            }, 3
        }
        };
}

TEST_P(FindSplitTests, whenFindSplitShouldReturnNumerRowWhenReflectsBegins)
{
    //Given
    auto [grid_to_check, expected_split] = GetParam();

    //When
    int founded_split = findSplit(grid_to_check);

    //Then
    ASSERT_EQ(founded_split, expected_split);
}

INSTANTIATE_TEST_SUITE_P(FindSplitTest, FindSplitTests, testing::ValuesIn(GenerateFindSplitParams()));

TEST(TransposeTest, transposeVector)
{
    Grid enter_grid {
        "##......#",
        "##......#"
    };

    Grid transposed_grid {
        "##",
        "##",
        "..",
        "..",
        "..",
        "..",
        "..",
        "..",
        "##"
    };

    ASSERT_EQ(transpose(enter_grid), transposed_grid);
}


TEST(IsFixableTest, OneCharacterDifference)
{
    std::string first = "..##..";
    std::string second = "...#..";

    ASSERT_TRUE(isFixable(first, second));
}

TEST(IsFixableTest, TwoCharacterDifference)
{
    std::string first = "..##..";
    std::string second = "#..#..";

    ASSERT_FALSE(isFixable(first, second));
}

