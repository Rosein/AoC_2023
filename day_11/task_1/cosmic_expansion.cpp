#include "cosmic_expansion.hpp"

bool CosmicExpansion::does_block_contain_galaxy(const int index, const TypeOfBlock type_of_block)
{
    const char kGalaxy = '#';
    if(type_of_block == TypeOfBlock::row)
    {
        for(std::size_t i = 0; i < cosmic_universe_[0].size(); ++i)
        {
            if(cosmic_universe_[index][i] == kGalaxy)
            {
                return true;
            }
        }
    } else if(type_of_block == TypeOfBlock::column)
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