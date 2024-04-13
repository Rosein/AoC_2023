#include "path_helper/path_helper.hpp"
#include "scan_edge_digits.hpp"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

void run_app(std::string filename)
{
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


int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_01/input"};
    run_app(filename);
    return 0;
}
