#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "mirage_maintenance.hpp"
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

    std::string line;

    while(std::getline(fs, line))
    {
        std::cout << line << std::endl;
    }

    fs.close();
}


int main()
{
    // run_app`();
    run_tests();
    return 0;
}

void run_tests()
{
    {
        DEBUG_PRINT_TESTNAME("Test calcucale_one_step_difference() #1:");
        const int depth = 1;
        std::vector<int> report {0, 3, 6, 9, 12, 15};
        std::vector<int> expected_report {3, 3, 3, 3, 3, 15};
        calcucale_one_step_difference(report, depth);

        assert(report == expected_report);
    }

    {
        DEBUG_PRINT_TESTNAME("Test calcucale_one_step_difference() #2:");
        const int depth = 2;
        std::vector<int> report {3, 3, 3, 3, 3, 15};
        std::vector<int> expected_report {0, 0, 0, 0, 3, 15};
        calcucale_one_step_difference(report, depth);

        assert(report == expected_report);
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}

/*

10  13  16  21  30  45
3   3   5   9   15  45
0   2   4   6   15  45
2   2   2   6   15  45
0   0   2   6   15  45

0   0   2   8   23  68




*/