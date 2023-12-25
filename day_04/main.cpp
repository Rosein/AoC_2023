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

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}

