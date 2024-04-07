#include "day_03/task_1/gear_ratios.hpp"
#include "gtest/gtest.h"

using AdjacentToSymbolTestParams =
    std::tuple<std::vector<std::string>, std::pair<int, int>, std::pair<int, int>, bool>;

class NumberAdjacentToSymbolParameterizedFixture
: public ::testing::TestWithParam<AdjacentToSymbolTestParams>
{
protected:
};

TEST_P(NumberAdjacentToSymbolParameterizedFixture, ShouldBeAdjacentAsExpected)
{
    auto [example_data, begin_index, end_index, expected_result] = GetParam();

    EXPECT_EQ(is_number_adjacent_to_symbol(example_data, begin_index, end_index), expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    VerifyIsNumberAdjacentToSymbol,
    NumberAdjacentToSymbolParameterizedFixture,
    testing::Values(
        std::make_tuple(std::vector<std::string>{{"...677.."}, {".....&.."}, {"........"}},
                        std::pair<int, int>{0, 3},
                        std::pair<int, int>{0, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"...677&"}, {"......."}, {"......."}},
                        std::pair<int, int>{0, 3},
                        std::pair<int, int>{0, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"..&677."}, {"......."}, {"......."}},
                        std::pair<int, int>{0, 3},
                        std::pair<int, int>{0, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"...677."}, {".....&"}, {"......."}},
                        std::pair<int, int>{0, 3},
                        std::pair<int, int>{0, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"677...."}, {"..&...."}, {"......."}},
                        std::pair<int, int>{0, 0},
                        std::pair<int, int>{0, 2},
                        true),
        std::make_tuple(std::vector<std::string>{{"677&...."}, {"........"}, {"........"}},
                        std::pair<int, int>{0, 0},
                        std::pair<int, int>{0, 2},
                        true),
        std::make_tuple(std::vector<std::string>{{"677...."}, {"&......"}, {"......."}},
                        std::pair<int, int>{0, 0},
                        std::pair<int, int>{0, 2},
                        true),
        std::make_tuple(std::vector<std::string>{{"......."}, {"...677."}, {".....&"}, {"......."}},
                        std::pair<int, int>{1, 3},
                        std::pair<int, int>{1, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"..&...."}, {"...677."}, {"......."}},
                        std::pair<int, int>{1, 3},
                        std::pair<int, int>{1, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"......."}, {"..&677."}, {"......."}},
                        std::pair<int, int>{1, 3},
                        std::pair<int, int>{1, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"........"}, {"...677&."}, {"........"}},
                        std::pair<int, int>{1, 3},
                        std::pair<int, int>{1, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"........"}, {"...677.."}, {"..&....."}},
                        std::pair<int, int>{1, 3},
                        std::pair<int, int>{1, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"......."}, {"..&...."}, {"...677."}},
                        std::pair<int, int>{2, 3},
                        std::pair<int, int>{2, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"......."}, {"......&"}, {"...677."}},
                        std::pair<int, int>{2, 3},
                        std::pair<int, int>{2, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"......."}, {"......."}, {"...677&"}},
                        std::pair<int, int>{2, 3},
                        std::pair<int, int>{2, 5},
                        true),
        std::make_tuple(std::vector<std::string>{{"......."}, {"......."}, {"...&677"}},
                        std::pair<int, int>{2, 4},
                        std::pair<int, int>{2, 6},
                        true),
        std::make_tuple(std::vector<std::string>{{"......."}, {".&....."}, {"....677"}},
                        std::pair<int, int>{2, 4},
                        std::pair<int, int>{2, 6},
                        false)));

using ExtractTestParams =
    std::tuple<std::vector<std::string>, std::pair<int, int>, std::pair<int, int>>;

class ExtractFixture : public ::testing::TestWithParam<ExtractTestParams>
{
protected:
    ExtractorOfNextNumberIndexes sut;
};

TEST_F(ExtractFixture, ShouldBeExtractOnceAsExpected)
{
    std::vector<std::string> example_data{{"......."}, {"...&..."}, {"....677"}};

    std::pair<int, int> begin_index = {2, 4};
    std::pair<int, int> end_index = {2, 6};

    ExtractorOfNextNumberIndexes extractor;
    auto result = extractor.extract(example_data);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value().first, begin_index);
    EXPECT_EQ(result.value().second, end_index);
}

TEST_F(ExtractFixture, ShouldBeExtractTwiceAsExpected)
{

    std::vector<std::string> example_data{{"..555.."}, {"......."}, {"...&..."}, {"....677"}};
    std::pair<int, int> begin_index = {0, 2};
    std::pair<int, int> end_index = {0, 4};

    ExtractorOfNextNumberIndexes extractor;
    auto result = extractor.extract(example_data);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value().first, begin_index);
    EXPECT_EQ(result.value().second, end_index);

    result = extractor.extract(example_data);

    begin_index = {3, 4};
    end_index = {3, 6};

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value().first, begin_index);
    EXPECT_EQ(result.value().second, end_index);
}

TEST(ExtractorOfNumberAdjacetToSymbolShould, ReturnNextPartNumberAsExpected)
{
    std::vector<std::string> example_data{{"..555.."}, {"......."}, {"...&..."}, {"....677"}};
    const int expected_next_part_number = 677;
    ExtractorOfNumberAdjacetToSymbol extractor;

    EXPECT_EQ(extractor.extract_next_part_number(example_data).value(), expected_next_part_number);
}

TEST(ExtractorOfNumberAdjacetToSymbolShould, ReturnSumOfTwoPartNumbersAsExpected)
{
    std::vector<std::string> example_data{{"..555.."}, {"......."},
                                          {"...^23."}, {"......."},
                                          {".../..."}, {"....677"}};
    const int expected_sum_of_two_part_numbers = 700;

    ExtractorOfNumberAdjacetToSymbol extractor;
    EXPECT_EQ(extractor.sum_part_numbers(example_data), expected_sum_of_two_part_numbers);
}

TEST(ExtractorOfNumberAdjacetToSymbolShould, ReturnSumOfAllPartNumbersAsExpected)
{
    std::vector<std::string> example_data{{"467..114.."}, {"...*......"},
                                          {"..35..633."}, {"......#..."},
                                          {"617*......"}, {".....+.58."},
                                          {"..592....."}, {"......755."},
                                          {"...$.*...."}, {".664.598.."}};
    const int expected_sum_of_all_part_numbers = 4361;

    ExtractorOfNumberAdjacetToSymbol extractor;
    assert(extractor.sum_part_numbers(example_data) == expected_sum_of_all_part_numbers);
}
