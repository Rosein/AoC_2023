#pragma once

#include "../debug_features.hpp"
#include <tuple>
#include <vector>

using DestinationRangeStart = int;
using SourceRangeStart = int;
using RangeLenght = int;

constexpr int kDestinationStart = 0;
constexpr int kSourceStart = 1;
constexpr int kRangeLenght = 2;

using MapSubcharacterisctic = std::tuple<DestinationRangeStart, SourceRangeStart, RangeLenght>;

int evaluate_value_of_mapping(int seed, std::vector<MapSubcharacterisctic> seed_to_soil_map);