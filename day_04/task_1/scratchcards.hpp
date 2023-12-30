#pragma once

#include <set>
#include <list>
#include <iomanip>
#include <sstream>

#include "../../debug_features.hpp"

int count_guessed_numbers(const std::set<int>& winning_numbers, std::list<int> scratched_numbers);
int calculate_round_points(const std::set<int>& winning_numbers, std::list<int> scratched_numbers);
std::set<int> extract_winning_numbers(std::string input);
std::list<int>  extract_scratched_numbers(std::string input);

