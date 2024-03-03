#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <map>
#include "camel_cards.hpp"
#include "../../debug_features.hpp"

void run_tests();

void run_app()
{
    // std::string filename{"input"};
    // std::fstream fs;
    // fs.open(filename);
    // if(!fs.is_open())
    // {
    //     std::cout << "File couldn't be open" << std::endl;
    // }

    // std::string hand;
    // int bid;

    // std::map<int, int> hand_of_cards{};

    // while(fs >> hand >> bid)
    // {
    //     HandOfCards cards = convert_string_hand_to_hand_type(hand);
    //     int key = transform_to_key(cards);
    //     hand_of_cards[key] = bid;
    // }

    // int sum{0};
    // int rank{1};

    // for (const auto& [key, value] : hand_of_cards)
    // {
    //     sum += (value * rank);
    //     rank++;
    // }
    // std::cout << sum << std::endl;

    // fs.close();
}


int main()
{
    // run_app();
    run_tests();
    return 0;
}

void run_tests()
{
    {
        DEBUG_PRINT_TESTNAME("Test has_five_of_a_kind() #1:");
        HandOfCards hand{'A', 'A', 'A', 'J', 'A'};

        assert(has_five_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_five_of_a_kind() #2:");
        HandOfCards hand{'J', 'J', 'J', 'J', 'J'};

        assert(has_five_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_five_of_a_kind() #3:");
        HandOfCards hand{'A', 'A', 'A', 'A', 'A'};

        assert(has_five_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_five_of_a_kind() #4:");
        HandOfCards hand{'A', 'A', 'A', 'J', '2'};

        assert(!has_five_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_four_of_a_kind() #1:");
        HandOfCards hand{'A', 'A', '2', 'J', 'A'};

        assert(has_four_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_four_of_a_kind() #2:");
        HandOfCards hand{'A', 'A', '2', 'J', 'J'};

        assert(has_four_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_four_of_a_kind() #3:");
        HandOfCards hand{'A', 'J', '2', 'J', 'J'};

        assert(has_four_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_four_of_a_kind() #4:");
        HandOfCards hand{'A', 'J', 'J', 'J', 'J'};

        assert(!has_four_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_four_of_a_kind() #5:");
        HandOfCards hand{'A', 'K', '2', 'J', 'A'};

        assert(!has_four_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_four_of_a_kind() #6:");
        HandOfCards hand{'A', 'A', '2', 'A', 'A'};

        assert(has_four_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_full_house() #1:");
        HandOfCards hand{'A', 'A', 'K', 'A', 'K'};

        assert(has_full_house(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_full_house() #2: GivenOneJokerAndThreeOfKind_ThenFourOfAKind");
        HandOfCards hand{'A', 'A', 'K', 'A', 'J'};

        assert(!has_full_house(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_full_house() #3:");
        HandOfCards hand{'A', 'K', 'K', 'A', 'J'};

        assert(has_full_house(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_full_house() #4:");
        HandOfCards hand{'A', 'K', 'K', 'J', 'J'};

        assert(!has_full_house(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_full_house() #5:");
        HandOfCards hand{'J', 'K', 'K', 'J', 'J'};

        assert(!has_full_house(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #1:");
        HandOfCards hand{'A', 'A', 'C', 'A', 'Q'};

        assert(has_three_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #2:");
        HandOfCards hand{'A', 'A', 'Q', 'A', 'Q'};

        assert(!has_three_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #3:");
        HandOfCards hand{'A', 'Q', 'K', 'A', 'K'};

        assert(!has_three_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #4:");
        HandOfCards hand{'A', 'Q', 'K', 'J', 'K'};

        assert(has_three_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #5:");
        HandOfCards hand{'A', 'Q', 'J', 'J', 'K'};

        assert(has_three_of_a_kind(hand));
    }


    {
        DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #6:");
        HandOfCards hand{'A', 'J', 'J', 'J', 'K'};

        assert(!has_three_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_two_pairs() #1:");
        HandOfCards hand{'A', 'K', 'K', 'A', '3'};

        assert(has_two_pairs(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_two_pairs() #2:");
        HandOfCards hand{'A', 'K', 'K', 'A', 'K'};

        assert(!has_two_pairs(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_two_pairs() #3:");
        HandOfCards hand{'A', '2', 'K', 'A', 'J'};

        assert(!has_two_pairs(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_two_pairs() #4:");
        HandOfCards hand{'A', '2', 'K', 'J', 'J'};

        assert(!has_two_pairs(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_two_pairs() #5:");
        HandOfCards hand{'A', 'K', 'K', 'J', 'J'};

        assert(!has_two_pairs(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_one_pair() #1:");
        HandOfCards hand{'A', 'Q', 'J', 'A', '9'};
        assert(!has_one_pair(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_one_pair() #2:");
        HandOfCards hand{'A', '1', '8', 'A', '9'};

        assert(has_one_pair(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_one_pair() #3:");
        HandOfCards hand{'A', '1', '8', 'J', 'J'};

        assert(!has_one_pair(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_one_pair() #4:");
        HandOfCards hand{'A', 'J', 'Q', '3', '9'};

        assert(has_one_pair(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_high_card() #1:");
        HandOfCards hand{'A', '2', 'Q', '3', '9'};

        assert(has_high_card(hand));
    }

      {
        DEBUG_PRINT_TESTNAME("Test has_high_card() #2:");
        HandOfCards hand{'A', 'J', 'Q', '3', '9'};

        assert(!has_high_card(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test transform_to_key() #1:");
        HandOfCards right_hand{'A', 'A', '8', 'A', 'A'};
        HandOfCards left_hand{'2', '3', '3', '3', '2'};

        auto right_key = transform_to_key(right_hand);
        auto left_key = transform_to_key(left_hand);

        assert(right_key > left_key);
    }

    {
        DEBUG_PRINT_TESTNAME("Test transform_to_key() #2:");
        HandOfCards right_hand{'A', 'A', 'A', 'A', 'A'};
        HandOfCards left_hand{'Q', 'Q', 'Q', 'Q', 'Q'};

        auto right_key = transform_to_key(right_hand);
        auto left_key = transform_to_key(left_hand);

        assert(right_key > left_key);
    }

    {
        DEBUG_PRINT_TESTNAME("Test transform_to_key() #3:");
        HandOfCards right_hand{'A', '2', '3', 'A', 'A'};
        HandOfCards left_hand{'Q', 'A', 'A', 'Q', '3'};

        auto right_key = transform_to_key(right_hand);
        auto left_key = transform_to_key(left_hand);

        assert(right_key > left_key);
    }

    {
        DEBUG_PRINT_TESTNAME("Test transform_to_key() #4:");
        HandOfCards right_hand{'A', '1', '3', '2', 'A'};
        HandOfCards left_hand{'Q', 'A', '2', '9', '3'};

        auto right_key = transform_to_key(right_hand);
        auto left_key = transform_to_key(left_hand);

        assert(right_key > left_key);
    }


    {
        DEBUG_PRINT_TESTNAME("Test transform_to_key() #6:");
        HandOfCards right_hand{'A', '5', '6', '2', 'A'};
        HandOfCards left_hand{'A', 'A', '5', '9', '6'};

        auto right_key = transform_to_key(right_hand);
        auto left_key = transform_to_key(left_hand);

        assert(right_key < left_key);
    }

    {
        DEBUG_PRINT_TESTNAME("Test transform_to_key() #7: Both high card, second stronger");
        HandOfCards right_hand{'Q', 'A', '7', '9', '3'};
        HandOfCards left_hand{'A', '3', '4', '2', '5'};

        auto right_key = transform_to_key(right_hand);
        auto left_key = transform_to_key(left_hand);

        assert(right_key < left_key);
    }

    {
        DEBUG_PRINT_TESTNAME("Test transform_to_key() #8: Same type, but joker is weaker then Q");
        HandOfCards right_hand{'Q', 'J', '7', '9', '3'};
        HandOfCards left_hand{'J', '3', '4', '2', '5'};

        auto right_key = transform_to_key(right_hand);
        auto left_key = transform_to_key(left_hand);

        assert(right_key > left_key);
    }

    {
        DEBUG_PRINT_TESTNAME("Test transform_to_key() #8: Same type, but joker is weaker then Q");
        HandOfCards right_hand{'Q', 'J', '7', '9', '3'};
        HandOfCards left_hand{'J', '3', '3', '2', '5'};

        auto right_key = transform_to_key(right_hand);
        auto left_key = transform_to_key(left_hand);

        assert(right_key < left_key);
    }

    {
        //        A23A4 ← HAND OF CARD
        //        ↓↓↓↓↓
        // 0x10000C01C2 ← HEX representation of card
        DEBUG_PRINT_TESTNAME("Test convert_to_hex_representation() #1:");
        HandOfCards hand{'A', '2', '3', 'A', '4'};
        int hex_hand{0xC12C3};

        assert(convert_to_hex_representation(hand) == hex_hand);
    }

    {
        //        A23AJ ← HAND OF CARD
        //        ↓↓↓↓↓
        // 0x10000C12C0 ← HEX representation of card
        DEBUG_PRINT_TESTNAME("Test convert_to_hex_representation() #2:");
        HandOfCards hand{'A', '2', '3', 'A', 'J'};
        int hex_hand{0xC12C0};

        assert(convert_to_hex_representation(hand) == hex_hand);
    }

    {
        DEBUG_PRINT_TESTNAME("Test convert string hand to hand type() #4: Both high card, second stronger");
        std::string string_hand{"QAJ9B"};
        HandOfCards expected_hand{'Q', 'A', 'J', '9', 'B'};

        assert(convert_string_hand_to_hand_type(string_hand) == expected_hand);
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}


/*














AJAA2 → High card + 3 x J

AJJAA → One pair + 3 x J


*/