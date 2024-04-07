#include "day_02/cube_conundrum.hpp"
#include "gtest/gtest.h"

TEST(CubeConundrumTest, IsGameSetPossible1)
{
    EXPECT_TRUE(is_game_set_possible(
        {{Color::blue, 10}, {Color::green, 2}, {Color::red, 6}}));
}

TEST(CubeConundrumTest, IsGameSetPossible2)
{
    EXPECT_FALSE(is_game_set_possible({{Color::blue, kMaximalPossibleGameSet[Color::blue] + 1},
                                       {Color::green, 2},
                                       {Color::red, 6}}));
}

TEST(CubeConundrumTest, IsGameSetPossible3)
{
    EXPECT_TRUE(is_game_set_possible({{Color::green, 2}, {Color::red, 6}}));
}

TEST(CubeConundrumTest, IsGamePossible)
{
    EXPECT_TRUE(
        is_game_possible("3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"));
}

TEST(CubeConundrumTest, ValidateGameResult1)
{
    std::string example_data{
        "Game 5: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"};
    EXPECT_TRUE(v1::validate_game_result(example_data) == 5);
}

TEST(CubeConundrumTest, AdjustMaxGameSet)
{
    GameSet first_game_set{{Color::blue, 3}, {Color::red, 4}};
    GameSet second_game_set{{Color::blue, 1}, {Color::red, 10}};
    GameSet candi_max_set{};

    adjust_max_game_set(first_game_set, candi_max_set);
    adjust_max_game_set(second_game_set, candi_max_set);

    EXPECT_TRUE(candi_max_set == (GameSet{{Color::blue, 3}, {Color::red, 10}}));
}

TEST(CubeConundrumTest, FindMaxAmountsForOneGame1)
{
    Game example_data{{{Color::blue, 3}, {Color::red, 4}},
                      {{Color::red, 1}, {Color::green, 2}, {Color::blue, 6}},
                      {{Color::green, 2}}};

    const GameSet expected_result{{Color::blue, 6}, {Color::red, 4}, {Color::green, 2}};
    EXPECT_TRUE(find_max_amounts_for_one_game(example_data) == expected_result);
}

TEST(CubeConundrumTest, FindMaxAmountsForOneGame2)
{
    Game example_data{{{Color::blue, 3}, {Color::red, 4}},
                      {{Color::red, 1}, {Color::green, 2}, {Color::blue, 6}},
                      {{Color::green, 2}}};

    EXPECT_TRUE(calculate_power_of_game(example_data) == 48);
}

TEST(CubeConundrumTest, ValidateGameResult2)
{
    std::string example_data{
        "Game 5: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"};
    EXPECT_TRUE(v2::validate_game_result(example_data) == 48);
}