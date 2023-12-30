#pragma once

#include <vector>
#include <string>
#include <optional>
#include <iomanip>

#include "../../debug_features.hpp"

using Coordinates = std::pair<int,int>;
using EngineSchematic = std::vector<std::string>;

bool is_number_adjacent_to_symbol(EngineSchematic engine_schematic, Coordinates begin_index, Coordinates end_index);

int extract_number(std::string engine_schematic_one_line);

int extract_number_when_symbol_is_adjacent(std::string engine_schematic_one_line);

class ExtractorOfNextNumberIndexes
{
public:
    std::optional<std::pair<Coordinates, Coordinates>> extract(EngineSchematic engine_schematic);
private:
    std::pair<Coordinates, Coordinates> next_indexes_{{0, 0}, {0, 0}};
};

class ExtractorOfNumberAdjacetToSymbol
{
public:
    int sum_part_numbers(EngineSchematic engine_schematic);
    std::optional<int> extract_next_part_number(EngineSchematic engine_schematic);
private:
    ExtractorOfNextNumberIndexes extractor_;
};
