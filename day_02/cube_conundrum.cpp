#include "cube_conundrum.hpp"
#include <sstream>
#include <iostream>
#include <ios>

std::ostream& operator<<(std::ostream& os, const Color& v) {
  switch(v) {
    case Color::green : os << "green"; break;
    case Color::red : os << "red"; break;
    case Color::blue : os << "blue"; break;
  }
  return os;
}

bool is_game_set_possible(const GameSet& game_set)
{
    bool is_possible = true;
    for(auto [color, amount] : game_set)
    {
        // std::cout << "Set[color, amount] : " << color << " " << amount << std::endl;

        if(kMaximalPossibleGameSet[color] < amount)
        {
            is_possible = false;
        }
    }
    // std::cout << std::endl;
    return is_possible;
}

Color convert_color_to_enum(std::string color)
{
    if(color == "red")
    {
        return Color::red;
    } 
    else if (color == "blue")
    {
        return Color::blue;
    } 
    else if (color == "green")
    {
        return Color::green;
    }
    return {};
}

GameSet convert_from_string_to_game_set(std::string game_set)
{
    std::stringstream ss{game_set};
    std::string cube_data;

    GameSet new_set;

    while(std::getline(ss, cube_data, ','))
    {
        std::stringstream cube_stream_conversion{cube_data};
        int amount{0};
        std::string color{};

        cube_stream_conversion >> amount >> color;
        new_set[convert_color_to_enum(color)] =  amount;
    }

    return new_set;
}


bool is_game_possible(const std::string game)
{

    Game gameSets;

    std::string game_set;
    std::stringstream ss{game}; 
    bool is_possible = true;

    while(std::getline(ss, game_set, ';'))
    {
        gameSets.emplace_back(convert_from_string_to_game_set(game_set));
    }

    for(auto& set : gameSets)
    {
        if(!is_game_set_possible(set))
        {
            is_possible = false;
        }
    }
    return is_possible;

}

int validate_game_result(const std::string game_with_prefix)
{
    std::stringstream ss{game_with_prefix};
    std::string prefix{};
    int index_of_game{};
    char colon{};
    std::string proper_game{};
    
    ss >> prefix >> index_of_game >> colon;
    std::getline(ss, proper_game);
    
    return is_game_possible(proper_game) ? index_of_game : 0;
}

void adjust_max_game_set(const GameSet& game_set, GameSet& max_set)
{
    for(const auto [color, amount] : game_set)
    {
      if(amount > max_set[color])
      {
        max_set[color] = amount;
      }
    }
}

GameSet find_max_amounts_for_one_game(const Game& game)
{
    GameSet max_game_set{};
    for(const auto& game_set : game)
    {
        adjust_max_game_set(game_set, max_game_set);
    }
    return max_game_set;
}
