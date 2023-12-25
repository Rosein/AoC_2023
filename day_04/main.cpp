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

    while(std::getline(fs, line))
    {
        std::cout << line << std::endl;
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
        DEBUG_PRINT_TESTNAME("Test count_guessed_numbers() #1:");

        std::set<int> winning_numbers{41, 48, 83, 86, 17};
        std::list<int> scratched_numbers{83, 86, 6, 31, 17, 9, 48, 53};

        assert(count_guessed_numbers(winning_numbers, scratched_numbers) == 4);
    }

    {
        DEBUG_PRINT_TESTNAME("Test calculate_round_points() #1:");

        std::set<int> winning_numbers{41, 48, 83, 86, 17};
        std::list<int> scratched_numbers{83, 86, 6, 31, 17, 9, 48, 53};

        assert(calculate_round_points(winning_numbers, scratched_numbers) == 8);
    }

    {
        DEBUG_PRINT_TESTNAME("Test calculate_round_points() #2:");

        std::set<int> winning_numbers{13, 32, 20, 16, 61};
        std::list<int> scratched_numbers{61, 30, 68, 82, 17, 32, 24, 19};

        assert(calculate_round_points(winning_numbers, scratched_numbers) == 2);
    }

    {
        DEBUG_PRINT_TESTNAME("Test calculate_round_points() #3:");

        std::set<int> winning_numbers{41, 92, 73, 84, 69};
        std::list<int> scratched_numbers{59, 84, 76, 51, 58, 5, 54, 83};

        assert(calculate_round_points(winning_numbers, scratched_numbers) == 1);
    }

    {
        DEBUG_PRINT_TESTNAME("Test calculate_round_points() #4:");

        std::set<int> winning_numbers{87, 83, 26, 28, 32};
        std::list<int> scratched_numbers{88, 30, 70, 12, 93, 22, 82, 36};

        assert(calculate_round_points(winning_numbers, scratched_numbers) == 0);
    }

    {
        DEBUG_PRINT_TESTNAME("Test extract_winning_numbers() #1:");

        std::string example_input_line{"Card 153: 50 23 26 14 83 51 12 13 37 68 | 93 58 56 98 39 55 92 54 36 29 50 85 42 49 66 61 14 70  7 75 51 87 37 30 96"};

        auto result = extract_winning_numbers(example_input_line);
        std::set<int> winning_numbers{50, 23, 26, 14, 83, 51, 12, 13, 37, 68};

        assert(result == winning_numbers);
    }


    {
        DEBUG_PRINT_TESTNAME("Test extract_scratched_numbers() #1:");

        std::string example_input_line{"Card 153: 50 23 26 14 83 51 12 13 37 68 | 93 58 56 98 39 55 92 54 36 29 50 85 42 49 66 61 14 70  7 75 51 87 37 30 96"};

        auto result = extract_scratched_numbers(example_input_line);
        std::set<int> scratched_numbers{93, 58, 56, 98, 39, 55, 92, 54, 36, 29, 50, 85, 42, 49, 66, 61, 14, 70,  7, 75, 51, 87, 37, 30, 96};
        
        assert(result == scratched_numbers);
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}

