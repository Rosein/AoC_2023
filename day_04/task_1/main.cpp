#include "scratchcards.hpp"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

void run_app()
{
    std::string filename{"/home/rkumanek/Repos/AoC_2023/day_04/task_1/input"};
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
        total_sum += calculate_round_points(extract_winning_numbers(line),
                                            extract_scratched_numbers(line));
    }

    std::cout << total_sum << std::endl;

    fs.close();
}

int main()
{
    run_app();
    return 0;
}
