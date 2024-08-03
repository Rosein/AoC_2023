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

    // When
    sut.expand_for_block_without_galaxy(index, TypeOfBlock::column);
    auto has_new_column_galaxy = sut.does_block_contain_galaxy(index + 1, TypeOfBlock::column);

    // Then
    ASSERT_EQ(sut.number_of_columns(), previous_galaxy_size + 1);
    ASSERT_FALSE(has_new_column_galaxy);
}

TEST_F(CosmicExpansionTest, GivenCosmicUniverseWhenExpandForRowWithoutGalaxyThenShouldExpandGalaxyVertically)
{
    // Given
    auto previous_galaxy_size = cosmic_universe[0].size();
    const auto index = 3U;
    ASSERT_TRUE(sut.does_block_contain_galaxy(index + 1, TypeOfBlock::row));

    // When
    sut.expand_for_block_without_galaxy(index, TypeOfBlock::row);
    auto has_new_row_galaxy = sut.does_block_contain_galaxy(index + 1, TypeOfBlock::row);

    // Then
    ASSERT_EQ(sut.number_of_rows(), previous_galaxy_size + 1);
    ASSERT_FALSE(has_new_row_galaxy);
}

TEST_F(CosmicExpansionTest, GivenCosmicUniverseWhenExpandForAllRowsWithoutGalaxyThenShouldExpandGalaxyVertically)
{
    // Given
    auto previous_galaxy_size = cosmic_universe[0].size();
    const auto first_new_row_index = 4U;
    const auto second_new_row_index = 9U;

    // When
    sut.expands_rows_without_galaxy();

    // Then
    ASSERT_EQ(sut.number_of_rows(), previous_galaxy_size + 2);
    ASSERT_FALSE(sut.does_block_contain_galaxy(first_new_row_index, TypeOfBlock::row));
    ASSERT_FALSE(sut.does_block_contain_galaxy(second_new_row_index, TypeOfBlock::row));
}

TEST_F(CosmicExpansionTest, GivenCosmicUniverseWhenExpandForAllColumnsWithoutGalaxyThenShouldExpandGalaxyHorizontally)
{
    // Given
    auto previous_galaxy_size = cosmic_universe[0].size();
    const auto first_new_column_index = 3U;
    const auto second_new_column_index = 7U;
    const auto third_new_column_index = 11U;

    // When
    sut.expands_columns_without_galaxy();

    // Then
    ASSERT_EQ(sut.number_of_columns(), previous_galaxy_size + 3);
    ASSERT_FALSE(sut.does_block_contain_galaxy(first_new_column_index, TypeOfBlock::column));
    ASSERT_FALSE(sut.does_block_contain_galaxy(second_new_column_index, TypeOfBlock::column));
    ASSERT_FALSE(sut.does_block_contain_galaxy(third_new_column_index, TypeOfBlock::column));
}

