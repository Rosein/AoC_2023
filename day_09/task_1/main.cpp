#include <string>
#include <fstream>
#include <sstream>
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

    // std::vector<Report> reports{};
    Report single_report;
    int sum{0};

    while(std::getline(fs, line))
    {
        std::stringstream ss{line};
        int value{0};
        while(ss >> value)
        {
            single_report.push_back(value);
        }

        calculate_extrapolated_values(single_report);
        sum += single_report.back();
        single_report.clear();

    }

    std::cout << sum <<std::endl;

    fs.close();
}


int main()
{
    run_app();
    // run_tests();
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

    {
        DEBUG_PRINT_TESTNAME("Test calcucale_final_values() #1:");
        std::vector<int> report {0, 3, 6, 9, 12, 15};
        std::vector<int> expected_report {0, 0, 0, 0, 3, 15};
        calcucale_final_values(report);

        assert(report == expected_report);
    }

    {
        DEBUG_PRINT_TESTNAME("Test calculate_extrapolated_values() #1:");
        std::vector<int> report {0, 3, 6, 9, 12, 15};
        std::vector<int> expected_extrapolated_values {0, 0, 0, 0, 3, 18};
        calculate_extrapolated_values(report);

        assert(report == expected_extrapolated_values);
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