#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <map>
#include "cube_conundrum.hpp"

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
    int sum{};

    while(std::getline(fs, line))
    {
       sum += v2::validate_game_result(line);
    }
    
    std::cout << sum << std::endl;
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
        assert(is_game_set_possible({{Color::blue, 10},{Color::green, 2}, {Color::red, 6}}));
    }

    {
        assert(!is_game_set_possible({{Color::blue, kMaximalPossibleGameSet[Color::blue] + 1},{Color::green, 2}, {Color::red, 6}}));
    }

    {
        assert(is_game_set_possible({{Color::green, 2}, {Color::red, 6}}));
    }

    {
        assert(is_game_possible("3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"));
    }

    {
        std::string example_data{"Game 5: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"};
        assert(v1::validate_game_result(example_data) == 5);
    }

    {
        GameSet first_game_set{{Color::blue, 3}, {Color::red, 4}};
        GameSet second_game_set{{Color::blue, 1}, {Color::red, 10}};
        GameSet candi_max_set{};

        adjust_max_game_set(first_game_set, candi_max_set);
        adjust_max_game_set(second_game_set, candi_max_set);

        assert(candi_max_set == (GameSet{{Color::blue, 3}, {Color::red, 10}}));
    }

    {
        Game example_data{{{Color::blue, 3}, {Color::red, 4}},
                          {{Color::red, 1}, {Color::green, 2}, {Color::blue, 6}},
                          {{Color::green, 2}}};

        const GameSet expected_result{{Color::blue, 6}, {Color::red, 4}, {Color::green, 2}};
        assert(find_max_amounts_for_one_game(example_data) == expected_result);
    }

    {
        Game example_data{{{Color::blue, 3}, {Color::red, 4}},
                          {{Color::red, 1}, {Color::green, 2}, {Color::blue, 6}},
                          {{Color::green, 2}}};

        assert(calculate_power_of_game(example_data) == 48);
    }

    {
        std::string example_data{"Game 5: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green"};
        assert(v2::validate_game_result(example_data) == 48);
    }


    std::cout << "Tests passed!" << std::endl;
}
