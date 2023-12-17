#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include <map>
#include "gear_ratios.hpp"


void run_tests();

void run_app()
{
    std::string filename{"input"};
    std::fstream fs;
    fs.open(filename);
    if(!fs.is_open())
    {
        std::cout << "File couldn't be open" << std::endl;
    }

    std::string line;
    EngineSchematic engine_schematic{};

    while(std::getline(fs, line))
    {
       engine_schematic.push_back(line);
    }

    // std::cout << ExtractorOfNumberAdjacetToSymbol{engine_schematic}.sum_part_numbers() << std::endl;

    fs.close();
}

int main()
{
    // run_app();
    run_tests();
    return 0;
}

void run_tests()
{
    {
        {
            std::vector<std::string> example_data{
                {"...677.."},
                {".....*.."},
                {"........"}
            };

            std::pair<int,int> begin_index = {0, 3};
            std::pair<int,int> end_index = {0, 5};

            ExtractorOfNumberAdjacetToSymbol extractor{example_data};

            assert(extractor.is_number_adjacent_to_symbol(begin_index, end_index).has_value());
            assert((extractor.is_number_adjacent_to_symbol(begin_index, end_index).value() == Coordinates{1, 5}));
        }

        {
            std::vector<std::string> example_data{
                {"...677&"},
                {"......."},
                {"......."}
            };

            std::pair<int,int> begin_index = {0, 3};
            std::pair<int,int> end_index = {0, 5};
            
            ExtractorOfNumberAdjacetToSymbol extractor{example_data};

            assert(!extractor.is_number_adjacent_to_symbol(begin_index, end_index).has_value());
        }

    //     {
    //         std::vector<std::string> example_data{
    //             {"..&677."},
    //             {"......."},
    //             {"......."}
    //         };

    //         std::pair<int,int> begin_index = {0, 3};
    //         std::pair<int,int> end_index = {0, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {"...677."},
    //             {".....&"},
    //             {"......."}
    //         };

    //         std::pair<int,int> begin_index = {0, 3};
    //         std::pair<int,int> end_index = {0, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {"677...."},
    //             {"..&...."},
    //             {"......."}
    //         };

    //         std::pair<int,int> begin_index = {0, 0};
    //         std::pair<int,int> end_index = {0, 2};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {"677&...."},
    //             {"........"},
    //             {"........"}
    //         };

    //         std::pair<int,int> begin_index = {0, 0};
    //         std::pair<int,int> end_index = {0, 2};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {"677...."},
    //             {"&......"},
    //             {"......."}
    //         };

    //         std::pair<int,int> begin_index = {0, 0};
    //         std::pair<int,int> end_index = {0, 2};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {"......."},
    //             {"...677."},
    //             {".....&"},
    //             {"......."}
    //         };

    //         std::pair<int,int> begin_index = {1, 3};
    //         std::pair<int,int> end_index = {1, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {".....&."},
    //             {"...677."},
    //             {"......."}
    //         };

    //         std::pair<int,int> begin_index = {1, 3};
    //         std::pair<int,int> end_index = {1, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {"..&...."},
    //             {"...677."},
    //             {"......."}
    //         };

    //         std::pair<int,int> begin_index = {1, 3};
    //         std::pair<int,int> end_index = {1, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }


    //     {
    //         std::vector<std::string> example_data{
    //             {"......."},
    //             {"..&677."},
    //             {"......."}
    //         };

    //         std::pair<int,int> begin_index = {1, 3};
    //         std::pair<int,int> end_index = {1, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }


    //     {
    //         std::vector<std::string> example_data{
    //             {"........"},
    //             {"...677&."},
    //             {"........"}
    //         };

    //         std::pair<int,int> begin_index = {1, 3};
    //         std::pair<int,int> end_index = {1, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }


    //     {
    //         std::vector<std::string> example_data{
    //             {"......."},
    //             {"...677."},
    //             {"......&"}
    //         };

    //         std::pair<int,int> begin_index = {1, 3};
    //         std::pair<int,int> end_index = {1, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {"........"},
    //             {"...677.."},
    //             {"..&....."}
    //         };

    //         std::pair<int,int> begin_index = {1, 3};
    //         std::pair<int,int> end_index = {1, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }


    //     {
    //         std::vector<std::string> example_data{
    //             {"......."},
    //             {"..&...."},
    //             {"...677."}
    //         };

    //         std::pair<int,int> begin_index = {2, 3};
    //         std::pair<int,int> end_index = {2, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }



    //     {
    //         std::vector<std::string> example_data{
    //             {"......."},
    //             {"......&"},
    //             {"...677."}
    //         };

    //         std::pair<int,int> begin_index = {2, 3};
    //         std::pair<int,int> end_index = {2, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {"......."},
    //             {"......."},
    //             {"...677&"}
    //         };

    //         std::pair<int,int> begin_index = {2, 3};
    //         std::pair<int,int> end_index = {2, 5};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {"......."},
    //             {"......."},
    //             {"...&677"}
    //         };

    //         std::pair<int,int> begin_index = {2, 4};
    //         std::pair<int,int> end_index = {2, 6};

    //         assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }

    //     {
    //         std::vector<std::string> example_data{
    //             {"......."},
    //             {".&....."},
    //             {"....677"}
    //         };

    //         std::pair<int,int> begin_index = {2, 4};
    //         std::pair<int,int> end_index = {2, 6};

    //         assert(!is_number_adjacent_to_symbol(example_data, begin_index, end_index));
    //     }
    }

    {
        DEBUG_PRINT_TESTNAME("Test extract() #1:");
        std::vector<std::string> example_data{
            {"......."},
            {"...*..."},
            {"....677"}
        };

        std::pair<int,int> begin_index = {2, 4};
        std::pair<int,int> end_index = {2, 6};

        ExtractorOfNextNumberIndexes extractor;
        auto result = extractor.extract(example_data);

        assert(result.has_value());
        assert(result.value().first == begin_index);
        assert(result.value().second == end_index);
    }

    // {
    //     DEBUG_PRINT_TESTNAME("Test extract() #2:");

    //     std::vector<std::string> example_data{
    //         {"..555.."},
    //         {"......."},
    //         {"...&..."},
    //         {"....677"}
    //     };
    //     std::pair<int,int> begin_index = {0, 2};
    //     std::pair<int,int> end_index = {0, 4};

    //     ExtractorOfNextNumberIndexes extractor;
    //     auto result = extractor.extract(example_data);

    //     assert(result.has_value());
    //     assert(result.value().first == begin_index);
    //     assert(result.value().second == end_index);

    //     result = extractor.extract(example_data);

    //     begin_index = {3, 4};
    //     end_index = {3, 6};

    //     assert(result.has_value());
    //     assert(result.value().first == begin_index);
    //     assert(result.value().second == end_index);
    // }

    {
        DEBUG_PRINT_TESTNAME("Test extract_next_part_number() #1:");

        std::vector<std::string> example_data{
            {"..555.."},
            {"......."},
            {"...*..."},
            {"....677"}
        };

        ExtractorOfNumberAdjacetToSymbol extractor{example_data};
        auto actual_result = extractor.extract_next_part_number();
        assert(actual_result.has_value());
        assert(actual_result.value().value == 677);
    }

    {
        DEBUG_PRINT_TESTNAME("Test extract_next_part_number() #1:");

        std::vector<std::string> example_data{
            {"..555.."},
            {"......."},
            {".../..."},
            {"....677"}
        };

        ExtractorOfNumberAdjacetToSymbol extractor{example_data};
        auto actual_result = extractor.extract_next_part_number();
        assert(!actual_result.has_value());
    }

    {
        DEBUG_PRINT_TESTNAME("Test save_potential_gear() #1:");

        std::vector<std::string> example_data{
            {"..555.."},
            {"......."},
            {"...*..."},
            {"....677"}
        };

        ExtractorOfNumberAdjacetToSymbol extractor{example_data};
        extractor.save_potential_gears();
        PotentialGears actual_result = extractor.get_potential_gears();

        Coordinates expected_coordinates{2,3};
        
        assert(actual_result.size() == 1);
        assert((actual_result.find({2,3}) != actual_result.end()));
        assert((actual_result[{2,3}].first == 677));
        assert((actual_result[{2,3}].second == 1));
    }


    {
        DEBUG_PRINT_TESTNAME("Test save_potential_gear() #2:");

        std::vector<std::string> example_data{
            {"......."},
            {"...555."},
            {"...*..."},
            {"....677"}
        };

        ExtractorOfNumberAdjacetToSymbol extractor{example_data};
        extractor.save_potential_gears();
        PotentialGears actual_result = extractor.get_potential_gears();

        Coordinates expected_coordinates{2,3};
        
        assert(actual_result.size() == 1);
        assert((actual_result.find({2,3}) != actual_result.end()));
        assert((actual_result[{2,3}].first == (375735)));
        assert((actual_result[{2,3}].second == 2));
    }


    {
        DEBUG_PRINT_TESTNAME("Test save_potential_gear() #3:");

        std::vector<std::string> example_data{
            {"467..114.."},
            {"...*......"},
            {"..35..633."},
            {"......#..."},
            {"617*......"}
        };

        ExtractorOfNumberAdjacetToSymbol extractor{example_data};
        extractor.save_potential_gears();
        PotentialGears actual_result = extractor.get_potential_gears();

        
        assert(actual_result.size() == 2);
        assert((actual_result[{1,3}].first == (16345)));
        assert((actual_result[{1,3}].second == 2));

        assert((actual_result[{4,3}].first == (617)));
        assert((actual_result[{4,3}].second == 1));
    }

    {
        DEBUG_PRINT_TESTNAME("Test sum_gear_ratio() #1:");
        std::vector<std::string> example_data
        {
            {"467..114.."},
            {"...*......"},
            {"..35..633."},
            {"......#..."},
            {"617*......"},
            {".....+.58."},
            {"..592....."},
            {"......755."},
            {"...$.*...."},
            {".664.598.."}
        };

        ExtractorOfNumberAdjacetToSymbol extractor{example_data};
        
        assert(extractor.sum_gear_ratio() == 467835);
    }

    std::cout << GREEN << "Tests passed!" << RESET << std::endl;
}

