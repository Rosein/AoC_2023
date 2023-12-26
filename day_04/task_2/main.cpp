#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "scratchcards.hpp"


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

    std::string line;
    int total_sum{0};
    while(std::getline(fs, line))
    {
        //total_sum += calculate_round_points(extract_winning_numbers(line), extract_scratched_numbers(line));
    }

    std::cout << total_sum << std::endl;

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
        DEBUG_PRINT_TESTNAME("Test execute_step_nr() #1:");

        std::map<CardNumber, Amount> card_amounts_expected{
            {1, 1},
            {2, 1},
            {3, 1},
            {4, 1},
            {5, 1}
        };
        int card_number_to_be_executed{1};
        std::set<int> winning_numbers{41, 48, 83, 86, 17};
        std::list<int> scratched_numbers{83, 86, 6, 31, 17, 9, 48, 53};

        CardScratcher card_scratcher;
        card_scratcher.execute_step_nr(card_number_to_be_executed, winning_numbers, scratched_numbers);
        assert(card_scratcher.get_card_amounts() == card_amounts_expected);
    }

    {
        DEBUG_PRINT_TESTNAME("Test execute_step_nr() #2:");

        std::map<CardNumber, Amount> card_amounts_before{
            {1, 1},
            {2, 1},
            {3, 1},
            {4, 1},
            {5, 1}
        };

        std::map<CardNumber, Amount> card_amounts_expected{
            {1, 1},
            {2, 2},
            {3, 2},
            {4, 2},
            {5, 1}
        };

        int card_number_to_be_executed{2};
        std::set<int> winning_numbers{13, 32, 20, 16, 61};
        std::list<int> scratched_numbers{61, 30, 68, 82, 17, 32, 24, 19};

        CardScratcher card_scratcher(card_amounts_before);
        card_scratcher.execute_step_nr(card_number_to_be_executed, winning_numbers, scratched_numbers);
        assert(card_scratcher.get_card_amounts() == card_amounts_expected);
    }

    {
        DEBUG_PRINT_TESTNAME("Test extract_card_number() #1:");

        std::string example_input_line{"Card 153: 50 23 26 14 83 51 12 13 37 68 | 93 58 56 98 39 55 92 54 36 29 50 85 42 49 66 61 14 70  7 75 51 87 37 30 96"};

        auto result = extract_card_number(example_input_line);
        int expected_card_number{153};

        assert(result == expected_card_number);
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}

