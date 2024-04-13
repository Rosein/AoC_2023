#include "day_03/task_2/gear_ratios.hpp"
#include "gtest/gtest.h"

class ExtractorOfNumberFixture : public ::testing::Test
{
protected:
    std::pair<int, int> begin_index = {0, 3};
    std::pair<int, int> end_index = {0, 5};
};

TEST_F(ExtractorOfNumberFixture, ShouldBeAdjacentToSymbol)
{
    std::vector<std::string> example_data{{"...677.."}, {".....*.."}, {"........"}};

    ExtractorOfNumberAdjacentToSymbol extractor{example_data};

    EXPECT_TRUE(extractor.is_number_adjacent_to_symbol(begin_index, end_index).has_value());
    EXPECT_EQ((extractor.is_number_adjacent_to_symbol(begin_index, end_index).value()),
              (Coordinates{1, 5}));
}

TEST(Test, extract1)
{
    std::vector<std::string> example_data{{"......."}, {"...*..."}, {"....677"}};

    std::pair<int, int> begin_index = {2, 4};
    std::pair<int, int> end_index = {2, 6};

    ExtractorOfNextNumberIndexes extractor;
    auto result = extractor.extract(example_data);

    EXPECT_TRUE(result.has_value());
    EXPECT_EQ(result.value().first, begin_index);
    EXPECT_EQ(result.value().second, end_index);
}

TEST(Test, extract_next_part_number1)
{
    std::vector<std::string> example_data{{"..555.."}, {"......."}, {"...*..."}, {"....677"}};

    ExtractorOfNumberAdjacentToSymbol extractor{example_data};
    auto actual_result = extractor.extract_next_part_number();
    EXPECT_TRUE(actual_result.has_value());
    EXPECT_EQ(actual_result.value().value, 677);
}

TEST(Test, save_potential_gear1)
{

    std::vector<std::string> example_data{{"......."}, {"...555."}, {"...*..."}, {"....677"}};

    ExtractorOfNumberAdjacentToSymbol extractor{example_data};
    extractor.save_potential_gears();
    PotentialGears actual_result = extractor.get_potential_gears();

    EXPECT_EQ(actual_result.size(), 1);
    EXPECT_NE(actual_result.find({2, 3}), actual_result.end());
    EXPECT_EQ((actual_result[{2, 3}].first), (375735));
    EXPECT_EQ((actual_result[{2, 3}].second), 2);
}

TEST(Test, save_potential_gear2)
{
    std::vector<std::string> example_data{{"467..114.."},
                                          {"...*......"},
                                          {"..35..633."},
                                          {"......#..."},
                                          {"617*......"}};

    ExtractorOfNumberAdjacentToSymbol extractor{example_data};
    extractor.save_potential_gears();
    PotentialGears actual_result = extractor.get_potential_gears();


    EXPECT_EQ(actual_result.size(), 2);
    EXPECT_EQ((actual_result[{1, 3}].first), (16345));
    EXPECT_EQ((actual_result[{1, 3}].second), 2);

    EXPECT_EQ((actual_result[{4, 3}].first), (617));
    EXPECT_EQ((actual_result[{4, 3}].second), 1);
}

TEST(Test, sum_gear_ratio1)
{
    std::vector<std::string> example_data{{"467..114.."}, {"...*......"},
                                          {"..35..633."}, {"......#..."},
                                          {"617*......"}, {".....+.58."},
                                          {"..592....."}, {"......755."},
                                          {"...$.*...."}, {".664.598.."}};

    ExtractorOfNumberAdjacentToSymbol extractor{example_data};

    EXPECT_EQ(extractor.sum_gear_ratios(), 467835);
}