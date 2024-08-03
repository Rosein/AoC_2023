#include "day_11/task_1/cosmic_expansion.hpp"
#include "gtest/gtest.h"

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
    CosmicExpansion sut{cosmic_universe};
};

TEST_P(CosmicUniverseTest, GivenCosmicUniverseWhenCheckDoesBlockContainGalaxyThenConfimartionIsAsExpected)
{
    // Given

    auto [index, type_of_block, expected_result] = GetParam();

    // When
    auto actual_result = sut.does_block_contain_galaxy(index, type_of_block);

    // Then
    ASSERT_EQ(actual_result, expected_result);
}

INSTANTIATE_TEST_SUITE_P(IsColmunGalaxieslessTest,
                         CosmicUniverseTest,
                         testing::ValuesIn(GenerateDoesBlockContainGalaxyParams()));

struct CosmicExpansionTest : ::testing::Test
{
    CosmicUniverse cosmic_universe =
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
    CosmicExpansion sut{cosmic_universe};
};

TEST_F(CosmicExpansionTest, GivenCosmicUniverseWhenExpandForColumnWithoutGalaxyThenShouldExpandGalaxyHorizontally)
{
    // Given
    auto previous_galaxy_size = cosmic_universe.size();
    auto index = 2U;
    ASSERT_TRUE(sut.does_block_contain_galaxy(index + 1, TypeOfBlock::column));

    // Then
    sut.expand_for_block_without_galaxy(index, TypeOfBlock::column);
    auto has_new_column_galaxy = sut.does_block_contain_galaxy(index + 1, TypeOfBlock::column);

    // When
    ASSERT_EQ(sut.size_of_columns(), previous_galaxy_size + 1);
    ASSERT_FALSE(has_new_column_galaxy);
}

TEST_F(CosmicExpansionTest, GivenCosmicUniverseWhenExpandForRowWithoutGalaxyThenShouldExpandGalaxyVertically)
{
    // Given
    auto previous_galaxy_size = cosmic_universe[0].size();
    const auto index = 3U;
    ASSERT_TRUE(sut.does_block_contain_galaxy(index + 1, TypeOfBlock::row));

    // Then
    sut.expand_for_block_without_galaxy(index, TypeOfBlock::row);
    auto has_new_row_galaxy = sut.does_block_contain_galaxy(index + 1, TypeOfBlock::row);

    // When
    ASSERT_EQ(sut.size_of_rows(), previous_galaxy_size + 1);
    ASSERT_FALSE(has_new_row_galaxy);
}

