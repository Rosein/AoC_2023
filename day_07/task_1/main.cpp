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
        DEBUG_PRINT_TESTNAME("Test hasFiveOfAKind() #1:");
        HandOfCards hand{'A', 'A', 'A', 'A', 'A'};

        assert(hasFiveOfAKind(hand));
    }

    {
        DEBUG_PRINT_TESTNAME("Test hasFourOfAKind() #1:");
        HandOfCards hand{'A', 'A', 'B', 'A', 'A'};

        assert(hasFourOfAKind(hand));
    }

        {
        DEBUG_PRINT_TESTNAME("Test hasFullHouse() #1:");
        HandOfCards hand{'A', 'A', 'B', 'A', 'B'};

        assert(hasFullHouse(hand));
    }



    // {
    //     DEBUG_PRINT_TESTNAME("Test transform_to_key() #1:");
    //     HandOfCards right_hand{'A', 'A', '8', 'A', 'A'};
    //     HandOfCards left_hand{'2', '3', '3', '3', '2'};

    //     auto right_key = transform_to_key(right_hand);
    //     auto left_key = transform_to_key(left_hand);

    //     assert(right_key > left_key);
    // }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}
