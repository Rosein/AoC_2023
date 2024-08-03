#pragma once
#include <deque>
#include <vector>
#include <string>

enum class TypeOfBlock
{
    row,
    column
};

using CosmicUniverse = std::deque<std::string>;
using GalaxyCoords = std::pair<int,int>;
using GalaxiesCoords = std::vector<GalaxyCoords>;

class CosmicExpansion
{
public:
    CosmicExpansion(const CosmicUniverse& cosmic_universe) : cosmic_universe_(cosmic_universe){};
    bool does_block_contain_galaxy(const int index, const TypeOfBlock type_of_block);
    void expand_for_block_without_galaxy(const int index, const TypeOfBlock type_of_block);
    void expands_rows_without_galaxy();
    void expands_columns_without_galaxy();

    GalaxiesCoords extract_galaxies_coordinates();

    std::size_t number_of_rows();
    std::size_t number_of_columns();
private:
    CosmicUniverse cosmic_universe_;
};
