#include "cosmic_expansion.hpp"
#include "path_helper/path_helper.hpp"
#include <fstream>
#include <iostream>
#include <string>

void run_tests();

void run_app(std::string filename)
{
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;
    CosmicUniverse cosmic_data;

    while(std::getline(fs, line))
    {
        // std::cout << line << std::endl;
        cosmic_data.push_back(line);
    }

    CosmicExpansion cosmic{cosmic_data};

    GalaxiesCoords coords = cosmic.extract_galaxies_coordinates();

    long long unsigned int total_distance{0};

    for(std::size_t i = 0; i < coords.size(); ++i)
    {
        for(std::size_t j = i + 1; j < coords.size(); ++j)
        {
            total_distance += cosmic.measure_distance_between(coords[i], coords[j]);
        }
    }
    std::cout << "Total distance: " << total_distance << std::endl;
    fs.close();
}


int main(int argc, char** argv)
{
    std::string filename =
        path_helper::prename + std::string{"/AoC_2023/day_11/task_2/input"};
    run_app(filename);
    return 0;
}
