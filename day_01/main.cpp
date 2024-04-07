#include "scan_edge_digits.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

void run_app()
{
    std::string filename{"/home/rkumanek/Repos/AoC_2023/day_01/input"};
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    unsigned long long total_sum{0ULL};
    std::string line;
    while(std::getline(fs, line))
    {
        total_sum += v2::merge_edge_digits(line);
    }

    std::cout << total_sum << std::endl;

    fs.close();
}


int main()
{
    run_app();
    return 0;
}
