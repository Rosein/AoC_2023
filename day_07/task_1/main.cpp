#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "camel_cards.hpp"
#include "../../debug_features.hpp"

void run_tests();

void run_app()
{
    std::string filename{"input_example"};
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;

    while(std::getline(fs, line))
    {
        std::cout << line <<std::endl;
    }

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
        HandOfCards hand{'A', 'A', 'A', 'A', 'A'};

        assert(has_five_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_four_of_a_kind() #1:");
        HandOfCards hand{'A', 'A', 'B', 'A', 'A'};

        assert(has_four_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #1:");
        HandOfCards hand{'A', 'A', 'C', 'A', 'B'};

        assert(has_three_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #2:");
        HandOfCards hand{'A', 'A', 'B', 'A', 'B'};

        assert(!has_three_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_three_of_a_kind() #3:");
        HandOfCards hand{'A', 'Q', 'B', 'A', 'B'};

        assert(!has_three_of_a_kind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_full_house() #1:");
        HandOfCards hand{'A', 'A', 'B', 'A', 'B'};

        assert(has_full_house(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_two_pairs() #1:");
        HandOfCards hand{'A', 'Q', 'B', 'A', 'B'};

        assert(has_two_pairs(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_one_pair() #1:");
        HandOfCards hand{'A', 'Q', 'J', 'A', 'B'};

        assert(has_one_pair(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test has_one_pair() #2:");
        HandOfCards hand{'A', 'J', 'J', 'A', 'B'};

        assert(!has_one_pair(hand));
    }


    {
        DEBUG_PRINT_TESTNAME("Test has_one_pair() #2:");
        HandOfCards hand{'A', 'J', 'Q', '3', 'B'};

        assert(has_high_card(hand));
    }


    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}
