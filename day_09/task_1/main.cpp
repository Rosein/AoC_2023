#include "mirage_maintenance.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


void run_app()
{
    std::string filename{
        "/home/rkumanek/Repos/AoC_2023/day_09/task_1/input_example"};
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;

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

    std::cout << sum << std::endl;

    fs.close();
}


int main()
{
    run_app();
    return 0;
}


/*

10  13  16  21  30  45
3   3   5   9   15  45
0   2   4   6   15  45
2   2   2   6   15  45
0   0   2   6   15  45

0   0   2   8   23  68


a  0   3   6   9  12  15
  b  3   3   3   3   3
    c  0   0   0   0


*/