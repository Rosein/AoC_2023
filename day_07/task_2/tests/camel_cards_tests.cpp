#include "day_07/task_2/camel_cards.hpp"
#include "gtest/gtest.h"
#include <functional>
#include <tuple>
#include <utility>

using HandEvaluatorTestParams = std::tuple<HandOfCards, bool>;

class HasFiveOfAKindParametrizedFixture : public ::testing::TestWithParam<HandEvaluatorTestParams>
{
};

TEST_P(HasFiveOfAKindParametrizedFixture, ShouldVerifyWhetherHasFiveOfAKindWorksAsExpected)
{
    auto [hand, expected_result] = GetParam();

    EXPECT_EQ(has_five_of_a_kind(hand), expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    ShouldVerifyWhetherHasFiveOfAKindWorksAsExpected,
    HasFiveOfAKindParametrizedFixture,
    testing::Values(std::make_tuple(HandOfCards{'A', 'A', 'A', 'J', 'A'}, true),
                    std::make_tuple(HandOfCards{'J', 'J', 'J', 'J', 'J'}, true),
                    std::make_tuple(HandOfCards{'A', 'A', 'A', 'A', 'A'}, true),
                    std::make_tuple(HandOfCards{'A', 'A', 'A', 'J', '2'}, false),
                    std::make_tuple(HandOfCards{'A', 'A', '2', 'J', 'A'}, false),
                    std::make_tuple(HandOfCards{'A', 'A', '2', 'J', 'J'}, false),
                    std::make_tuple(HandOfCards{'A', 'J', '2', 'J', 'J'}, false),
                    std::make_tuple(HandOfCards{'A', 'J', 'J', 'J', 'J'}, true),
                    std::make_tuple(HandOfCards{'A', 'K', '2', 'J', 'A'}, false),
                    std::make_tuple(HandOfCards{'A', 'A', '2', 'A', 'A'}, false)));

class HasFourOfAKindParametrizedFixture : public ::testing::TestWithParam<HandEvaluatorTestParams>
{
};

TEST_P(HasFourOfAKindParametrizedFixture, ShouldVerifyWhetherHasFourOfAKindWorksAsExpected)
{
    auto [hand, expected_result] = GetParam();

    EXPECT_EQ(has_four_of_a_kind(hand), expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    ShouldVerifyWhetherHasFourOfAKindWorksAsExpected,
    HasFourOfAKindParametrizedFixture,
    testing::Values(std::make_tuple(HandOfCards{'A', 'A', '2', 'J', 'A'}, true),
                    std::make_tuple(HandOfCards{'A', 'A', '2', 'J', 'J'}, true),
                    std::make_tuple(HandOfCards{'A', 'J', '2', 'J', 'J'}, true),
                    std::make_tuple(HandOfCards{'A', 'J', 'J', 'J', 'J'}, false),
                    std::make_tuple(HandOfCards{'A', 'K', '2', 'J', 'A'}, false),
                    std::make_tuple(HandOfCards{'A', 'A', '2', 'A', 'A'}, true)));

class HasFullHouseParametrizedFixture : public ::testing::TestWithParam<HandEvaluatorTestParams>
{
};

TEST_P(HasFullHouseParametrizedFixture, ShouldVerifyWhetherHasFullHouseWorksAsExpected)
{
    auto [hand, expected_result] = GetParam();

    EXPECT_EQ(has_full_house(hand), expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    ShouldVerifyWhetherHasFullHouseWorksAsExpected,
    HasFullHouseParametrizedFixture,
    testing::Values(std::make_tuple(HandOfCards{'A', 'A', 'K', 'A', 'K'}, true),
                    std::make_tuple(HandOfCards{'A', 'A', 'K', 'A', 'J'}, false),
                    std::make_tuple(HandOfCards{'A', 'K', 'K', 'A', 'J'}, true),
                    std::make_tuple(HandOfCards{'A', 'K', 'K', 'J', 'J'}, false),
                    std::make_tuple(HandOfCards{'J', 'K', 'K', 'J', 'J'}, false)));

class HasThreeOfAKindParametrizedFixture : public ::testing::TestWithParam<HandEvaluatorTestParams>
{
};

TEST_P(HasThreeOfAKindParametrizedFixture, ShouldVerifyWhetherHasThreeOfAKindWorksAsExpected)
{
    auto [hand, expected_result] = GetParam();

    EXPECT_EQ(has_three_of_a_kind(hand), expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    ShouldVerifyWhetherHasThreeOfAKindWorksAsExpected,
    HasThreeOfAKindParametrizedFixture,
    testing::Values(std::make_tuple(HandOfCards{'A', 'A', 'C', 'A', 'Q'}, true),
                    std::make_tuple(HandOfCards{'A', 'A', 'Q', 'A', 'Q'}, false),
                    std::make_tuple(HandOfCards{'A', 'Q', 'K', 'A', 'K'}, false),
                    std::make_tuple(HandOfCards{'A', 'Q', 'K', 'J', 'K'}, true),
                    std::make_tuple(HandOfCards{'A', 'J', 'J', 'J', 'K'}, false)));

class HasTwoPairsParametrizedFixture : public ::testing::TestWithParam<HandEvaluatorTestParams>
{
};

TEST_P(HasTwoPairsParametrizedFixture, ShouldVerifyWhetherHasTwoPairsWorksAsExpected)
{
    auto [hand, expected_result] = GetParam();

    EXPECT_EQ(has_two_pairs(hand), expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    ShouldVerifyWhetherHasTwoPairsWorksAsExpected,
    HasTwoPairsParametrizedFixture,
    testing::Values(std::make_tuple(HandOfCards{'A', 'K', 'K', 'A', '3'}, true),
                    std::make_tuple(HandOfCards{'A', 'K', 'K', 'A', 'K'}, false),
                    std::make_tuple(HandOfCards{'A', '2', 'K', 'A', 'J'}, false),
                    std::make_tuple(HandOfCards{'A', '2', 'K', 'J', 'J'}, false),
                    std::make_tuple(HandOfCards{'A', 'K', 'K', 'J', 'J'}, false)));

class HasOnePairParametrizedFixture : public ::testing::TestWithParam<HandEvaluatorTestParams>
{
};

TEST_P(HasOnePairParametrizedFixture, ShouldVerifyWhetherHasOnePairWorksAsExpected)
{
    auto [hand, expected_result] = GetParam();

    EXPECT_EQ(has_one_pair(hand), expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    ShouldVerifyWhetherHasOnePairWorksAsExpected,
    HasOnePairParametrizedFixture,
    testing::Values(std::make_tuple(HandOfCards{'A', 'Q', 'J', 'A', '9'}, false),
                    std::make_tuple(HandOfCards{'A', '1', '8', 'A', '9'}, true),
                    std::make_tuple(HandOfCards{'A', '1', '8', 'J', 'J'}, false),
                    std::make_tuple(HandOfCards{'A', 'J', 'Q', '3', '9'}, true)));

class HasHighCardParametrizedFixture : public ::testing::TestWithParam<HandEvaluatorTestParams>
{
};

TEST_P(HasHighCardParametrizedFixture, ShouldVerifyWhetherHasHighCardWorksAsExpected)
{
    auto [hand, expected_result] = GetParam();

    EXPECT_EQ(has_high_card(hand), expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    ShouldVerifyWhetherHasHighCardWorksAsExpected,
    HasHighCardParametrizedFixture,
    testing::Values(std::make_tuple(HandOfCards{'A', '2', 'Q', '3', '9'}, true),
                    std::make_tuple(HandOfCards{'A', 'J', 'Q', '3', '9'}, false)));


using HandComparasionTestParams = std::pair<HandOfCards, HandOfCards>;

class HandGreaterComparasionParametrizedFixture
: public ::testing::TestWithParam<HandComparasionTestParams>
{
};

TEST_P(HandGreaterComparasionParametrizedFixture, ShouldConfirmRightHandIsGreaterThenLeft)
{
    auto right_hand = GetParam().first;
    auto left_hand = GetParam().second;

    auto right_key = transform_to_key(right_hand);
    auto left_key = transform_to_key(left_hand);
    EXPECT_GT(right_key, left_key);
}

INSTANTIATE_TEST_SUITE_P(
    ConfirmRightHandIsGreaterThenLeft,
    HandGreaterComparasionParametrizedFixture,
    testing::Values(std::make_pair(HandOfCards{'A', 'A', '8', 'A', 'A'},
                                   HandOfCards{'2', '3', '3', '3', '2'}),
                    std::make_pair(HandOfCards{'A', 'A', 'A', 'A', 'A'},
                                   HandOfCards{'Q', 'Q', 'Q', 'Q', 'Q'}),
                    std::make_pair(HandOfCards{'A', '2', '3', 'A', 'A'},
                                   HandOfCards{'Q', 'A', 'A', 'Q', '3'}),
                    std::make_pair(HandOfCards{'A', '1', '3', '2', 'A'},
                                   HandOfCards{'Q', 'A', '2', '9', '3'}),
                    std::make_pair(HandOfCards{'Q', 'J', '7', '9', '3'},
                                   HandOfCards{'J', '3', '4', '2', '5'})));

class HandLesserComparasionParametrizedFixture
: public ::testing::TestWithParam<HandComparasionTestParams>
{
};

TEST_P(HandLesserComparasionParametrizedFixture, ShouldConfirmRightHandIsLesserThenLeft)
{
    HandOfCards right_hand = GetParam().first;
    HandOfCards left_hand = GetParam().second;

    auto right_key = transform_to_key(right_hand);
    auto left_key = transform_to_key(left_hand);
    EXPECT_LT(right_key, left_key);
}

INSTANTIATE_TEST_SUITE_P(
    ConfirmRightHandIsLesserThenLeft,
    HandLesserComparasionParametrizedFixture,
    testing::Values(std::make_pair(HandOfCards{'A', '5', '6', '2', 'A'},
                                   HandOfCards{'A', 'A', '5', '9', '6'}),
                    std::make_pair(HandOfCards{'Q', 'A', '7', '9', '3'},
                                   HandOfCards{'A', '3', '4', '2', '5'}),
                    std::make_pair(HandOfCards{'Q', 'J', '7', '9', '3'},
                                   HandOfCards{'J', '3', '3', '2', '5'})));

using ConversionToHexTestParams = std::pair<HandOfCards, int>;

class ConversionToHexRepresentationParameterizedFixture
: public ::testing::TestWithParam<ConversionToHexTestParams>
{
};

TEST_P(ConversionToHexRepresentationParameterizedFixture, ShouldVerifyConversionToHex)
{
    auto hand = GetParam().first;
    auto expected_hex_hand = GetParam().second;

    EXPECT_EQ(convert_to_hex_representation(hand), expected_hex_hand);
}

// ####### First ###########################
//        A23A4 ← HAND OF CARD
//        ↓↓↓↓↓
// 0x10000C01C2 ← HEX representation of card
//
// ####### Second ###########################
//        A23AJ ← HAND OF CARD
//        ↓↓↓↓↓
// 0x10000C12C0 ← HEX representation of card
INSTANTIATE_TEST_SUITE_P(
    VerifyConversionToHex,
    ConversionToHexRepresentationParameterizedFixture,
    testing::Values(std::make_pair(HandOfCards{'A', '2', '3', 'A', '4'}, 0xC12C3),
                    std::make_pair(HandOfCards{'A', '2', '3', 'A', 'J'}, 0xC12C0)));

TEST(ConversionFromStringHand, ReturnExpectedHandType)
{
    std::string string_hand{"QAJ9B"};
    HandOfCards expected_hand{'Q', 'A', 'J', '9', 'B'};

    EXPECT_EQ(convert_string_hand_to_hand_type(string_hand), expected_hand);
}
