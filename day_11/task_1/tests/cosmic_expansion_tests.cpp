#include "day_11/task_1/cosmic_expansion.hpp"
#include "gtest/gtest.h"

enum class TypeOfBlock
{
    row,
    column
};

using DoesBlockContainGalaxyParams =
    std::tuple<std::size_t, TypeOfBlock, bool>;

std::vector<DoesBlockContainGalaxyParams> GenerateDoesBlockContainGalaxyParams()
{
    return std::vector<DoesBlockContainGalaxyParams>{
        {2U, TypeOfBlock::column, false},
        {3U, TypeOfBlock::column, true},
        {9U, TypeOfBlock::column, true},
        {3U, TypeOfBlock::row, false},
        {4U, TypeOfBlock::row, true},
        };
}

struct CosmicUniverseTest : public ::testing::TestWithParam<DoesBlockContainGalaxyParams>
{
    const CosmicUniverse cosmic_universe =
    {"...#......",
     ".......#..",
     "#.........",
     "..........",
     "......#...",
     ".#........",
     ".........#",
     "..........",
     ".......#..",
     "#...#....."};
};

TEST_P(CosmicUniverseTest, GivenCosmicUniverse_WhenCheckDoesBlockContainGalaxy_ThenConfimartionIsAsExpected)
{
    // Given
    auto [index, type_of_block, expected_result] = GetParam();

    // When
    auto actual_result = does_block_contain_galaxy(index, type_of_block);

    // Then
    ASSERT_EQ(actual_result, expected_result);
}

INSTANTIATE_TEST_SUITE_P(IsColmunGalaxieslessTest,
                         CosmicUniverseTest,
                         testing::ValuesIn(GenerateDoesBlockContainGalaxyParams()));
