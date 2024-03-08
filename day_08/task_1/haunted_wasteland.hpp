#pragma once

#include "../../debug_features.hpp"

#include <map>
#include <string>
#include <utility>

using DesertPlan = std::map<std::string,std::pair<std::string, std::string>>;

std::string go_to_next_place(const DesertPlan& plan, const std::string& current_position, const char direction);