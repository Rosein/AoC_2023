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

Color convertColorToEnum(std::string color)
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

GameSet convertFromStringToGameSet(std::string game_set)
{
    std::stringstream gs{game_set};
    std::string cube_data;

    GameSet new_set;

    while(std::getline(gs, cube_data, ','))
    {
        std::stringstream cube_stream_conversion{cube_data};
        int amount{0};
        std::string color{};

        cube_stream_conversion >> amount >> color;
        new_set[convertColorToEnum(color)] =  amount;
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
        gameSets.emplace_back(convertFromStringToGameSet(game_set));
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