#include "day_04/task_1/scratchcards.hpp"
#include "gtest/gtest.h"

class ScratchedNumbersFixture : public ::testing::Test
{
protected:
    std::set<int> winning_numbers{41, 48, 83, 86, 17};
    std::list<int> scratched_numbers{83, 86, 6, 31, 17, 9, 48, 53};
};

TEST_F(ScratchedNumbersFixture, CountGuessedNumberTest)
{
    EXPECT_EQ(count_guessed_numbers(winning_numbers, scratched_numbers), 4);
}

TEST_F(ScratchedNumbersFixture, CalculateRoundPointsTest)
{
    EXPECT_EQ(calculate_round_points(winning_numbers, scratched_numbers), 8);
}

class ScratchedNumbersParameterizedFixture
: public ::testing::TestWithParam<std::tuple<std::set<int>, std::list<int>, int>>
{
};

TEST_P(ScratchedNumbersParameterizedFixture, VerifyTheExpectedResult)
{
    auto [winning_numbers, scratched_numbers, expected_round_points] = GetParam();

    EXPECT_EQ(calculate_round_points(winning_numbers, scratched_numbers), expected_round_points);
}

INSTANTIATE_TEST_SUITE_P(
    CalculateRoundPointsParamTest,
    ScratchedNumbersParameterizedFixture,
    testing::Values(std::make_tuple(std::set<int>{13, 32, 20, 16, 61},
                                    std::list<int>{61, 30, 68, 82, 17, 32, 24, 19},
                                    2),
                    std::make_tuple(std::set<int>{41, 92, 73, 84, 69},
                                    std::list<int>{59, 84, 76, 51, 58, 5, 54, 83},
                                    1),
                    std::make_tuple(std::set<int>{87, 83, 26, 28, 32},
                                    std::list<int>{88, 30, 70, 12, 93, 22, 82, 36},
                                    0)));

class ExtractNumbersFixture : public ::testing::Test
{
protected:
    std::string example_input_line{
        "Card 153: 50 23 26 14 83 51 12 13 37 68 | 93 58 56 98 39 55 92 54 "
        "36 29 50 85 42 49 66 61 14 70  7 75 51 87 37 30 96"};
};


TEST_F(ExtractNumbersFixture, VerifyExtractionOfWinningNumbers)
{
    auto result = extract_winning_numbers(example_input_line);
    std::set<int> winning_numbers{50, 23, 26, 14, 83, 51, 12, 13, 37, 68};

    EXPECT_EQ(result, winning_numbers);
}


TEST_F(ExtractNumbersFixture, VerifyExtractionOfScratchedNumbers)
{
    auto result = extract_scratched_numbers(example_input_line);
    std::list<int> scratched_numbers{93, 58, 56, 98, 39, 55, 92, 54, 36,
                                     29, 50, 85, 42, 49, 66, 61, 14, 70,
                                     7,  75, 51, 87, 37, 30, 96};

    EXPECT_EQ(result, scratched_numbers);
}
