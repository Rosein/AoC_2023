#pragma once

#include<map>
#include <vector>
#include <string>
#include <iostream>


enum class Color 
{
    red,
    green,
    blue
};

std::ostream& operator<<(std::ostream& os, const Color& v);

using GameSet = std::map<Color,int>;
using Game =  std::vector<GameSet>;

static GameSet kMaximalPossibleGameSet{
    {Color::red, 12},
    {Color::green, 13},
    {Color::blue, 14}
};

bool is_game_set_possible(const GameSet& game_set);

bool is_game_possible(const std::string game);