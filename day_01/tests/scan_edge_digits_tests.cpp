#include "day_01/scan_edge_digits.hpp"
#include "gtest/gtest.h"

TEST(MergeEdgeDigits, ExpectWellTransform1)
{
    std::string wellformed_input{"two2seven7"};
    EXPECT_EQ(v1::merge_edge_digits(wellformed_input), 27);
}

TEST(MergeEdgeDigits, ExpectWellTransform2)
{
    std::string wellformed_input{"qfqtkz9fivetst"};
    EXPECT_EQ(v1::merge_edge_digits(wellformed_input), 99);
}

class MergeEdgeDigitsV2ParameterizedFixture
: public ::testing::TestWithParam<std::tuple<std::string, int>>
{
};

TEST_P(MergeEdgeDigitsV2ParameterizedFixture, ExpectWellTransform)
{
    auto [wellformed_input, expected_result] = GetParam();
    EXPECT_EQ(v2::merge_edge_digits(wellformed_input), expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    VerifySecondVersion,
    MergeEdgeDigitsV2ParameterizedFixture,
    testing::Values(
        std::make_tuple(std::string{"asdfasdfsevenasdfasdf"}, 77),
        std::make_tuple(std::string{"three2seven7"}, 37),
        std::make_tuple(std::string{"1three2seven7"}, 17),
        std::make_tuple(std::string{"5threesevenasdfasdf"}, 57),
        std::make_tuple(std::string{"threesevenasdfasdf"}, 37),
        std::make_tuple(std::string{"threeonesevenasdfasdf"}, 37),
        std::make_tuple(std::string{"three8oneseven43asdfasdf"}, 33),
        std::make_tuple(std::string{"threone"}, 11),
        std::make_tuple(std::string{"23"}, 23),
        std::make_tuple(std::string{"2three"}, 23),
        std::make_tuple(std::string{"twothree"}, 23),
        std::make_tuple(std::string{"two3"}, 23),
        std::make_tuple(std::string{"two"}, 22),
        std::make_tuple(std::string{"2"}, 22),
        std::make_tuple(std::string{"five2seven"}, 57),
        std::make_tuple(std::string{"5twoseven"}, 57),
        std::make_tuple(std::string{"five2seven"}, 57),
        std::make_tuple(std::string{"twothreefive"}, 25),
        std::make_tuple(std::string{"twothree5"}, 25),
        std::make_tuple(std::string{"235"}, 25),
        std::make_tuple(std::string{"23five"}, 25),
        std::make_tuple(std::string{"2three5"}, 25),
        std::make_tuple(std::string{"2threefive"}, 25),
        std::make_tuple(std::string{"two35"}, 25),
        std::make_tuple(std::string{"two3five"}, 25),
        std::make_tuple(std::string{"msgbxbbtb3pnlnjsixthreefoureightwobm"}, 32),
        std::make_tuple(std::string{"5vn"}, 55),
        std::make_tuple(std::string{"cvvpszdheight6"}, 86),
        std::make_tuple(std::string{"1twoeightsix"}, 16),
        std::make_tuple(std::string{"x8"}, 88),
        std::make_tuple(std::string{"6four1fcmhbpmbknkpxthpcthreesevenonethre"
                                    "e"},
                        63)));
