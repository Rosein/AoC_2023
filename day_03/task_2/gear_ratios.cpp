#include "gear_ratios.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>

std::ostream& operator<<(std::ostream& os, Coordinates coordinates)
{
    os << "{" << coordinates.first << ", " << coordinates.second << "}";
    return os;
}

bool is_symbol(const char character)
{
    return character == '*';
}

bool are_indexes_in_scope(const EngineSchematic& engine_schematic, int first, int second)
{
    return 0 <= first && first < engine_schematic.size() &&
           0 <= second && second < engine_schematic[0].size();
}

std::optional<Coordinates> ExtractorOfNumberAdjacentToSymbol::is_number_adjacent_to_symbol(Coordinates begin_index, Coordinates end_index)
{
    // PRECONDTION(zakładamy, że koło liczby jest conajwyżej jedna gwiazdka());

    if(begin_index.first < engine_schematic_.size() -1)
    {
        for(int i = begin_index.second - 1; i <= end_index.second + 1; i++)
        {
            if(are_indexes_in_scope(engine_schematic_, begin_index.first + 1, i) &&
               is_symbol(engine_schematic_[begin_index.first + 1][i]))
            {
                return Coordinates{begin_index.first + 1, i};
            }
        }
    }

    if(are_indexes_in_scope(engine_schematic_, end_index.first, end_index.second + 1) &&
       is_symbol(engine_schematic_[end_index.first][end_index.second + 1]))
    {
        return Coordinates{end_index.first, end_index.second + 1};
    }

    if(are_indexes_in_scope(engine_schematic_, begin_index.first, begin_index.second - 1) &&
       is_symbol(engine_schematic_[begin_index.first][begin_index.second - 1]))
    {
        return Coordinates{begin_index.first, begin_index.second - 1};
    }

    for(int i = begin_index.second - 1; i <= end_index.second + 1; i++)
    {
        if(begin_index.first > 0){
            if(are_indexes_in_scope(engine_schematic_, begin_index.first - 1, i) &&
               is_symbol(engine_schematic_[begin_index.first - 1][i]))
            {
                return Coordinates{begin_index.first - 1, i};
            }
        }
    }
    return std::nullopt;
}

int find_nr_of_column_of_last_digit_in_sequence(const std::string& row, int begin_index_of_number)
{
    bool is_continous_digit_sequence = true;

    int i = begin_index_of_number;
    for(; i < row.size(); ++i)
    {
        if(!std::isdigit(row[i]))
        {
            is_continous_digit_sequence = false;
            break;
        }
    }

    return i - 1;
}

std::optional<std::pair<Coordinates, Coordinates>> ExtractorOfNextNumberIndexes::extract(EngineSchematic engine_schematic)
{

    for(auto row = next_indexes_.first.first; row < engine_schematic.size(); ++row )
    {
        for(auto character = next_indexes_.first.second; character < engine_schematic[row].size(); ++character)
        {
            if(std::isdigit(engine_schematic[row][character]))
            {
                next_indexes_.second.first = next_indexes_.first.first;
                next_indexes_.second.second = find_nr_of_column_of_last_digit_in_sequence(engine_schematic[row], next_indexes_.first.second);

                DEBUG_PRINT(next_indexes_.first << " " << next_indexes_.second);
                auto return_indexes = next_indexes_;

                next_indexes_.first = next_indexes_.second;
                if(next_indexes_.first.second + 1 != engine_schematic[row].size())
                {
                    next_indexes_.first.second++;
                }
                else
                {
                    next_indexes_.first.first++;
                    next_indexes_.first.second = 0;
                }
                return return_indexes;
            }

            next_indexes_.first.second++;
        }
        next_indexes_.first.first++;
        next_indexes_.first.second = 0;
    }

    return std::nullopt;
}

std::optional<NumberDescription> ExtractorOfNumberAdjacentToSymbol::extract_next_part_number()
{
    while(true)
    {
        auto number_to_check_indexes =  extractor_.extract(engine_schematic_);
        if(!number_to_check_indexes.has_value())
        {
            DEBUG_PRINT("Didn't find any number");
            return std::nullopt;
        }

        if(is_number_adjacent_to_symbol(number_to_check_indexes.value().first, number_to_check_indexes.value().second).has_value())
        {
            DEBUG_PRINT("")
            const std::string& row_with_number = engine_schematic_[number_to_check_indexes.value().first.first];

            const int& index_of_first_digit_of_number = number_to_check_indexes.value().first.second;
            const int& index_of_first_last_of_number = number_to_check_indexes.value().second.second;
            const int part_number{std::stoi(row_with_number.substr(index_of_first_digit_of_number, index_of_first_last_of_number + 1))};
            DEBUG_PRINT("Founded part number: " << part_number);
            return NumberDescription{part_number, number_to_check_indexes.value().first, number_to_check_indexes.value().second};
        }
    }
}

int ExtractorOfNumberAdjacentToSymbol::sum_part_numbers()
{
    int total_sum_of_part_numbers{0};
    while(true)
    {
        auto candi_part_number = extract_next_part_number();

        if(candi_part_number.has_value())
        {
            DEBUG_PRINT("candi_part_number: " << candi_part_number.value().value);
            total_sum_of_part_numbers += candi_part_number.value().value;
            DEBUG_PRINT("total_sum_of_part_numbers: " << total_sum_of_part_numbers);
        }
        else
        {
            DEBUG_PRINT("total_sum_of_part_numbers: " << total_sum_of_part_numbers);
            return total_sum_of_part_numbers;
        }
    }
    return total_sum_of_part_numbers;
}

void ExtractorOfNumberAdjacentToSymbol::save_potential_gear(std::optional<NumberDescription>  number_to_check)
{
    if(number_to_check.has_value())
    {
        std::cout << "number_to_check: " << number_to_check.value().value << std::endl;
        auto symbol_coords = is_number_adjacent_to_symbol(number_to_check.value().begin_number, number_to_check.value().end_number);

        if(potential_gears_.find(symbol_coords.value()) == potential_gears_.end()){
            potential_gears_[symbol_coords.value()] = {1, 0};
        }

        potential_gears_[symbol_coords.value()].first *= number_to_check.value().value;
        (potential_gears_[symbol_coords.value()].second)++;

        DEBUG_PRINT("potential_gears_[symbol_coords.value()].first: " << potential_gears_[symbol_coords.value()].first);
    }
}

PotentialGears& ExtractorOfNumberAdjacentToSymbol::get_potential_gears()
{
    return potential_gears_;
}

void ExtractorOfNumberAdjacentToSymbol::save_potential_gears()
{
    auto candi_part_number{extract_next_part_number()};

    while(candi_part_number.has_value())
    {
        save_potential_gear(candi_part_number);
        candi_part_number = extract_next_part_number();
    }
}

int ExtractorOfNumberAdjacentToSymbol::sum_gear_ratios()
{
    int total_sum_gear_ratios{0};

    save_potential_gears();
    auto potential_gears_ = get_potential_gears();
    for(auto [symbol_coordinate, pair] : potential_gears_)
    {
        auto& product = pair.first;
        auto& counter = pair.second;

        if(counter == 2)
        {
            total_sum_gear_ratios += product;
        }
    }

    return total_sum_gear_ratios;
}