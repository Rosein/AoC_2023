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

    while(std::getline(fs, line))
    {
       std::cout << line << std::endl;
    }
    
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
                {".....&.."},
                {"........"}
            };

            std::pair<int,int> begin_index = {0, 3};
            std::pair<int,int> end_index = {0, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {"...677&"},
                {"......."},
                {"......."}
            };

            std::pair<int,int> begin_index = {0, 3};
            std::pair<int,int> end_index = {0, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {"..&677."},
                {"......."},
                {"......."}
            };

            std::pair<int,int> begin_index = {0, 3};
            std::pair<int,int> end_index = {0, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {"...677."},
                {".....&"},
                {"......."}
            };

            std::pair<int,int> begin_index = {0, 3};
            std::pair<int,int> end_index = {0, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {"677...."},
                {"..&...."},
                {"......."}
            };

            std::pair<int,int> begin_index = {0, 0};
            std::pair<int,int> end_index = {0, 2};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {"677&...."},
                {"........"},
                {"........"}
            };

            std::pair<int,int> begin_index = {0, 0};
            std::pair<int,int> end_index = {0, 2};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {"677...."},
                {"&......"},
                {"......."}
            };

            std::pair<int,int> begin_index = {0, 0};
            std::pair<int,int> end_index = {0, 2};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {"......."},
                {"...677."},
                {".....&"},
                {"......."}
            };

            std::pair<int,int> begin_index = {1, 3};
            std::pair<int,int> end_index = {1, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {".....&."},
                {"...677."},
                {"......."}
            };

            std::pair<int,int> begin_index = {1, 3};
            std::pair<int,int> end_index = {1, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {"..&...."},
                {"...677."},
                {"......."}
            };

            std::pair<int,int> begin_index = {1, 3};
            std::pair<int,int> end_index = {1, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }


        {
            std::vector<std::string> example_data{
                {"......."},
                {"..&677."},
                {"......."}
            };

            std::pair<int,int> begin_index = {1, 3};
            std::pair<int,int> end_index = {1, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }


        {
            std::vector<std::string> example_data{
                {"........"},
                {"...677&."},
                {"........"}
            };

            std::pair<int,int> begin_index = {1, 3};
            std::pair<int,int> end_index = {1, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }
        

        {
            std::vector<std::string> example_data{
                {"......."},
                {"...677."},
                {"......&"}
            };

            std::pair<int,int> begin_index = {1, 3};
            std::pair<int,int> end_index = {1, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }
        
        {
            std::vector<std::string> example_data{
                {"........"},
                {"...677.."},
                {"..&....."}
            };

            std::pair<int,int> begin_index = {1, 3};
            std::pair<int,int> end_index = {1, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }
        

        {
            std::vector<std::string> example_data{
                {"......."},
                {"..&...."},
                {"...677."} 
            };

            std::pair<int,int> begin_index = {2, 3};
            std::pair<int,int> end_index = {2, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }
        


        {
            std::vector<std::string> example_data{
                {"......."},
                {"......&"},
                {"...677."} 
            };

            std::pair<int,int> begin_index = {2, 3};
            std::pair<int,int> end_index = {2, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }
        
        {
            std::vector<std::string> example_data{
                {"......."},
                {"......."},
                {"...677&"} 
            };

            std::pair<int,int> begin_index = {2, 3};
            std::pair<int,int> end_index = {2, 5};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {"......."},
                {"......."},
                {"...&677"} 
            };

            std::pair<int,int> begin_index = {2, 4};
            std::pair<int,int> end_index = {2, 6};

            assert(is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }

        {
            std::vector<std::string> example_data{
                {"......."},
                {".&....."},
                {"....677"} 
            };

            std::pair<int,int> begin_index = {2, 4};
            std::pair<int,int> end_index = {2, 6};

            assert(!is_number_adjacent_to_symbol(example_data, begin_index, end_index));
        }
    }    

    {
        std::vector<std::string> example_data{
            {"......."},
            {"...&..."},
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

    {
        std::vector<std::string> example_data{
            {"..555.."},
            {"......."},
            {"...&..."},
            {"....677"} 
        };
        std::pair<int,int> begin_index = {0, 2};
        std::pair<int,int> end_index = {0, 4};

        ExtractorOfNextNumberIndexes extractor;
        auto result = extractor.extract(example_data);

        assert(result.has_value());   
        assert(result.value().first == begin_index);   
        assert(result.value().second == end_index);  

        result = extractor.extract(example_data);

        begin_index = {3, 4};
        end_index = {3, 6};

        assert(result.has_value());   
        assert(result.value().first == begin_index);   
        assert(result.value().second == end_index);  

    }


    std::cout << "Tests passed!" << std::endl;
}
