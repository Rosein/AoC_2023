#include "cosmic_expansion.hpp"
#include <cassert>

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

std::size_t CosmicExpansion::size_of_rows()
{
    return cosmic_universe_.size();
}

std::size_t CosmicExpansion::size_of_columns()
{
    assert(not cosmic_universe_.empty());
    return cosmic_universe_.front().size();
}

void CosmicExpansion::expand_for_block_without_galaxy(const int index, const TypeOfBlock type_of_block)
{
    assert(not does_block_contain_galaxy(index, type_of_block));

    const char kEmptySpace = '.';
    if(is_row(type_of_block))
    {
        const auto empty_row = std::string(cosmic_universe_.front().size(), kEmptySpace);
        const auto where_to_put = std::next(std::begin(cosmic_universe_), index);
        cosmic_universe_.insert(where_to_put, empty_row);

    } else if(is_column(type_of_block))
    {
        for(std::size_t i = 0U; i < size_of_rows(); ++i)
        {
            const int kHowMany = 1;
            cosmic_universe_[i].insert(index, kHowMany, kEmptySpace);
        }
    }
}
