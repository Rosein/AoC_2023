#pragma once

#include <iomanip>
#include <map>
#include <optional>
#include <string>
#include <vector>

#include "debug_features/debug_features.hpp"


using Coordinates = std::pair<int, int>;
using EngineSchematic = std::vector<std::string>;
using PotentialGears = std::map<Coordinates, std::pair<int, int>>;

struct NumberDescription
{
    int value;
    Coordinates begin_number;
    Coordinates end_number;
};

int extract_number(std::string engine_schematic_one_line);

int extract_number_when_symbol_is_adjacent(std::string engine_schematic_one_line);

class ExtractorOfNextNumberIndexes
{
public:
    std::optional<std::pair<Coordinates, Coordinates>> extract(EngineSchematic engine_schematic);

private:
    std::pair<Coordinates, Coordinates> next_indexes_{{0, 0}, {0, 0}};
};

class ExtractorOfNumberAdjacentToSymbol
{
public:
    ExtractorOfNumberAdjacentToSymbol(EngineSchematic engine_schematic)
    : engine_schematic_(engine_schematic){};

    std::optional<Coordinates> is_number_adjacent_to_symbol(Coordinates begin_index,
                                                            Coordinates end_index);
    int sum_part_numbers();
    std::optional<NumberDescription> extract_next_part_number();
    void save_potential_gear(std::optional<NumberDescription> number_to_check);
    void save_potential_gears();
    PotentialGears& get_potential_gears();
    int sum_gear_ratios();

private:
    PotentialGears potential_gears_;
    ExtractorOfNextNumberIndexes extractor_;
    EngineSchematic engine_schematic_;
};
