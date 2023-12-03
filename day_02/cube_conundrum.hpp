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

int validate_game_result(const std::string prefix_game);

void adjust_max_game_set(const GameSet& game_set, GameSet& max_set);

GameSet find_max_amounts_for_one_game(const Game& game);