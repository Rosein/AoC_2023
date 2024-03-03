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
    std::string filename{"input"};
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string hand;
    int bid;

    std::map<int, int> hand_of_cards{};

    while(fs >> hand >> bid)
    {
        HandOfCards cards = convert_string_hand_to_hand_type(hand);
        int key = transform_to_key(cards);
        hand_of_cards[key] = bid;
    }

    int sum{0};
    int rank{1};

    for (const auto& [key, value] : hand_of_cards)
    {
        sum += (value * rank);
        rank++;
    }
    std::cout << sum << std::endl;

    fs.close();
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

    // {
    //     DEBUG_PRINT_TESTNAME("Test has_four_of_a_kind() #1:");
    //     HandOfCards hand{'A', 'A', 'B', 'A', 'A'};

    //     assert(has_four_of_a_kind(hand));
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #1:");
    //     HandOfCards hand{'A', 'A', 'C', 'A', 'B'};

    //     assert(has_three_of_a_kind(hand));
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #2:");
    //     HandOfCards hand{'A', 'A', 'B', 'A', 'B'};

    //     assert(!has_three_of_a_kind(hand));
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #3:");
    //     HandOfCards hand{'A', 'Q', 'B', 'A', 'B'};

    //     assert(!has_three_of_a_kind(hand));
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test has_full_house() #1:");
    //     HandOfCards hand{'A', 'A', 'B', 'A', 'B'};

    //     assert(has_full_house(hand));
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test has_two_pairs() #1:");
    //     HandOfCards hand{'A', 'Q', 'B', 'A', 'B'};

    //     assert(has_two_pairs(hand));
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test has_one_pair() #1:");
    //     HandOfCards hand{'A', 'Q', 'J', 'A', 'B'};

    //     assert(has_one_pair(hand));
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test has_one_pair() #2:");
    //     HandOfCards hand{'A', 'J', 'J', 'A', 'B'};

    //     assert(!has_one_pair(hand));
    // }


    // {
    //     DEBUG_PRINT_TESTNAME("Test has_one_pair() #2:");
    //     HandOfCards hand{'A', 'J', 'Q', '3', 'B'};

    //     assert(has_high_card(hand));
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test transform_to_key() #1:");
    //     HandOfCards right_hand{'A', 'A', '8', 'A', 'A'};
    //     HandOfCards left_hand{'2', '3', '3', '3', '2'};

    //     auto right_key = transform_to_key(right_hand);
    //     auto left_key = transform_to_key(left_hand);

    //     assert(right_key > left_key);
    // }


    // {
    //     DEBUG_PRINT_TESTNAME("Test transform_to_key() #2:");
    //     HandOfCards right_hand{'A', 'A', 'A', 'A', 'A'};
    //     HandOfCards left_hand{'Q', 'Q', 'Q', 'Q', 'Q'};

    //     auto right_key = transform_to_key(right_hand);
    //     auto left_key = transform_to_key(left_hand);

    //     assert(right_key > left_key);
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test transform_to_key() #3:");
    //     HandOfCards right_hand{'A', 'C', 'B', 'A', 'A'};
    //     HandOfCards left_hand{'Q', 'A', 'A', 'Q', 'B'};

    //     auto right_key = transform_to_key(right_hand);
    //     auto left_key = transform_to_key(left_hand);

    //     assert(right_key > left_key);
    // }

    // {
    //     DEBUG_PRINT_TESTNAME("Test transform_to_key() #3:");
    //     HandOfCards right_hand{'A', 'C', 'B', '2', 'A'};
    //     HandOfCards left_hand{'Q', 'A', 'J', '9', 'B'};

    //     auto right_key = transform_to_key(right_hand);
    //     auto left_key = transform_to_key(left_hand);

    //     assert(right_key > left_key);
    // }


    // {
    //     DEBUG_PRINT_TESTNAME("Test transform_to_key() #3:");
    //     HandOfCards right_hand{'A', 'C', 'B', '2', 'A'};
    //     HandOfCards left_hand{'Q', 'A', 'J', '9', 'B'};

    //     auto right_key = transform_to_key(right_hand);
    //     auto left_key = transform_to_key(left_hand);

    //     assert(right_key > left_key);
    // }

    {
        //        A23A4 ← HAND OF CARD
        //        ↓↓↓↓↓
        // 0x10000C01C2 ← HEX representation of card
        DEBUG_PRINT_TESTNAME("Test convert_to_hex_representation() #1:");
        HandOfCards hand{'A', '2', '3', 'A', '4'};
        int hex_hand{0xC01C2};

        assert(convert_to_hex_representation(hand) == hex_hand);
    }

    // {
    //     DEBUG_PRINT_TESTNAME("Test transform_to_key() #4: Both high card, second stronger");
    //     HandOfCards right_hand{'Q', 'A', 'J', '9', 'B'};
    //     HandOfCards left_hand{'A', 'C', 'B', '2', 'D'};

    //     auto right_key = transform_to_key(right_hand);
    //     auto left_key = transform_to_key(left_hand);

    //     assert(right_key < left_key);
    // }

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