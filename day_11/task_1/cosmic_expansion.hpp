#pragma once
#include <deque>
#include <string>

enum class TypeOfBlock
{
    row,
    column
};

using CosmicUniverse = std::deque<std::string>;

class CosmicExpansion
{
public:
    CosmicExpansion(const CosmicUniverse& cosmic_universe) : cosmic_universe_(cosmic_universe){};
    bool does_block_contain_galaxy(const int index, const TypeOfBlock type_of_block);
    void expand_for_block_without_galaxy(const int index, const TypeOfBlock type_of_block);

    std::size_t size_of_rows();
    std::size_t size_of_columns();
private:
    CosmicUniverse cosmic_universe_;
};
