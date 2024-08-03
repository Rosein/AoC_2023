#include "cosmic_expansion.hpp"
#include <cassert>
#include <cmath>

bool is_row(TypeOfBlock type_of_block)
{
    return type_of_block == TypeOfBlock::row;
}

bool is_column(TypeOfBlock type_of_block)
{
    return type_of_block == TypeOfBlock::column;
}

bool CosmicExpansion::does_block_contain_galaxy(const int index, const TypeOfBlock type_of_block)
{
    const char kGalaxy = '#';
    if(is_row(type_of_block))
    {
        for(std::size_t i = 0; i < cosmic_universe_.front().size(); ++i)
        {
            if(cosmic_universe_[index][i] == kGalaxy)
            {
                return true;
            }
        }
    } else if(is_column(type_of_block))
    {
        for(std::size_t i = 0; i < cosmic_universe_.size(); ++i)
        {
            if(cosmic_universe_[i][index] == kGalaxy)
            {
                return true;
            }
        }
    }
    return false;
}

std::size_t CosmicExpansion::number_of_rows()
{
    return cosmic_universe_.size();
}

std::size_t CosmicExpansion::number_of_columns()
{
    assert(not cosmic_universe_.empty());
    return cosmic_universe_.front().size();
}

void CosmicExpansion::expand_for_block_without_galaxy(const int index, const TypeOfBlock type_of_block)
{
    assert(not does_block_contain_galaxy(index, type_of_block));

    const char kEmptySpace = '.';
    const int kHowMany = 1;
    if(is_row(type_of_block))
    {
        const auto empty_row = std::string(cosmic_universe_.front().size(), kEmptySpace);
        const auto where_to_put = std::next(std::begin(cosmic_universe_), index);
        cosmic_universe_.insert(where_to_put, kHowMany, empty_row);

    } else if(is_column(type_of_block))
    {
        for(std::size_t i = 0U; i < number_of_rows(); ++i)
        {
            cosmic_universe_[i].insert(index, kHowMany, kEmptySpace);
        }
    }
}

void CosmicExpansion::expands_rows_without_galaxy()
{
    for(std::size_t i = 0; i < number_of_rows(); ++i)
    {
        if(not does_block_contain_galaxy(i, TypeOfBlock::row))
        {
            expand_for_block_without_galaxy(i, TypeOfBlock::row);
            ++i;
        }
    }
}

void CosmicExpansion::expands_columns_without_galaxy()
{
    for(std::size_t i = 0; i < number_of_columns(); ++i)
    {
        if(not does_block_contain_galaxy(i, TypeOfBlock::column))
        {
            expand_for_block_without_galaxy(i, TypeOfBlock::column);
            ++i;
        }
    }
}

GalaxiesCoords CosmicExpansion::extract_galaxies_coordinates()
{
    GalaxiesCoords galaxies_coords{};

    for(std::size_t i = 0; i < number_of_rows(); ++i)
    {
        for(std::size_t j = 0; j < number_of_columns(); ++j)
        {
            if(cosmic_universe_[i][j] == '#')
            {
                galaxies_coords.emplace_back(i,j);
            }
        }
    }

    return galaxies_coords;
}

int CosmicExpansion::measure_distance_between(const GalaxyCoords& first_galaxy, const GalaxyCoords&  second_galaxy)
{
    GalaxyCoords left_top_corner{std::min(first_galaxy.first, second_galaxy.first), std::min(first_galaxy.second, second_galaxy.second)};
    GalaxyCoords right_bottom_corner{std::max(first_galaxy.first, second_galaxy.first), std::max(first_galaxy.second, second_galaxy.second)};
    int distance{0};
    const int kBonusDueToGalaxyAbsence{1000'000};

    for(int i = left_top_corner.first; i < right_bottom_corner.first; ++i)
    {
        if(does_block_contain_galaxy(i, TypeOfBlock::row))
        {
            ++distance;
        }
        else
        {
            distance += kBonusDueToGalaxyAbsence;
        }

    }

    for(int i = left_top_corner.second; i < right_bottom_corner.second; ++i)
    {
        if(does_block_contain_galaxy(i, TypeOfBlock::column))
        {
            ++distance;
        }
        else
        {
            distance += kBonusDueToGalaxyAbsence;
        }

    }
    return distance;
}
