#include "day_06/task_1/boat_race.hpp"
#include "gtest/gtest.h"


class TimeToWinFixture : public ::testing::Test
{
protected:
    long long int time{7};
    long long int distance{9};
};

TEST_F(TimeToWinFixture, ShouldLoadingTimeBeEnoughToWin)
{

    long long int loading_time{3};

    EXPECT_TRUE(is_loading_time_enough_to_win(time, distance, loading_time));
}

TEST_F(TimeToWinFixture, ShouldTheShortestLoadingTimeToWinReturnTwo)
{
    long long int expected_loading_time{2};

    EXPECT_EQ(find_the_shortest_loading_time_to_win(time, distance), expected_loading_time);
}

TEST_F(TimeToWinFixture, ShouldTheLongestLoadingTimeToWinReturnFive)
{
    long long int expected_loading_time{5};

    EXPECT_EQ(find_the_longest_loading_time_to_win(time, distance), expected_loading_time);
}

class CountWinningParameterizedFixture
: public ::testing::TestWithParam<std::tuple<long long int, long long int, long long int>>
{
};

TEST_P(CountWinningParameterizedFixture, ReturnExpectedWinninOptions)
{
    auto [time, distance, expected_winning_options] = GetParam();
    EXPECT_EQ(count_winning_strategies(time, distance), expected_winning_options);
}

INSTANTIATE_TEST_SUITE_P(CountWinningShould,
                         CountWinningParameterizedFixture,
                         testing::Values(std::make_tuple(7, 9, 4),
                                         std::make_tuple(15, 40, 8),
                                         std::make_tuple(30, 200, 9)));
