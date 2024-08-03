#pragma once
#include <vector>
#include <string>

enum class TypeOfBlock
{
    row,
    column
};

using CosmicUniverse = std::vector<std::string>;

class CosmicExpansion
{
public:
    CosmicExpansion(const CosmicUniverse& cosmic_universe) : cosmic_universe_(cosmic_universe){};
    bool does_block_contain_galaxy(const int index, const TypeOfBlock type_of_block);

private:
    CosmicUniverse cosmic_universe_;

};
