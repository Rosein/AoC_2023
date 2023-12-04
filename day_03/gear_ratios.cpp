#include "gear_ratios.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

std::ostream& operator<<(std::ostream& os, Coordinates coordinates)
{
    os << "{" << coordinates.first << ", " << coordinates.second << "}";
    return os;
}

bool is_number_adjacent_to_symbol(EngineSchematic engine_schematic, Coordinates begin_index, Coordinates end_index)
{

    // std::cout << "Begin idnex: {,} : "  <<  begin_index.first << " " << begin_index.second <<std::endl;
    // std::cout << "End idnex: {,} : "  <<  end_index.first << " " << end_index.second <<std::endl;
    const char kCheckedSymbol{'&'};
   
    if(begin_index.first < engine_schematic.size() -1 ) 
    {
        for(int i = begin_index.second - 1; i <= end_index.second + 1; i++)
        {
            if(engine_schematic[begin_index.first + 1][i] == kCheckedSymbol)
            {
                return true;
            }
        }
    }

    if(engine_schematic[end_index.first][end_index.second + 1] == kCheckedSymbol)
    {
        return true;
    }

    if(engine_schematic[begin_index.first][begin_index.second - 1] == kCheckedSymbol)
    {
        return true;
    }

    for(int i = begin_index.second - 1; i <= end_index.second + 1; i++)
    {
        if(engine_schematic[begin_index.first - 1][i] == kCheckedSymbol)
        {
            return true;
        }
    }    

    return false;
}

int find_nr_of_column_of_last_digit_in_sequence(const std::string& row, int begin_index_of_number)
{
    bool is_continous_digit_sequence = true;
    
    int i = begin_index_of_number;
    for(; i < row.size() && is_continous_digit_sequence; ++i)
    {
        if(!std::isdigit(row[i]))
        {
            is_continous_digit_sequence = false;
        }
    }

    return i - 1;
}

std::optional<std::pair<Coordinates, Coordinates>> extract_next_number_indexes(EngineSchematic engine_schematic)
{
    static std::pair<Coordinates, Coordinates> next_indexes{{0, 0}, {0, 0}};

    for(const auto& row : engine_schematic)
    {
        for(const auto& character : row)
        {
            if(std::isdigit(character))
            {
                next_indexes.second.first = next_indexes.first.first;
                next_indexes.second.second = find_nr_of_column_of_last_digit_in_sequence(row, next_indexes.first.second);

                // std::cout << next_indexes.first << " " << next_indexes.second << std::endl;
                return next_indexes;
            }

            next_indexes.first.second++;
        }
        next_indexes.first.first++;
        next_indexes.first.second = 0;
    }

    return std::nullopt;
}