#include <algorithm>
#include <string>
#include <fstream>
#include <iostream>
#include <cassert>
#include "scan_edge_digits.hpp"

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

    unsigned long long total_sum{0ULL};
    std::string line;
    while(std::getline(fs, line))
    {
        // std::cout << line << std::endl;
        total_sum += v2::merge_edge_digits(line);
    }

    std::cout << total_sum << std::endl;

    fs.close();
}


int main()
{
    run_app();
    // run_tests();
    return 0;
}

void run_tests()
{
    {
        std::string wellformed_input{"two2seven7"};
        assert(v1::merge_edge_digits(wellformed_input) == 27);
    }

    {
        std::string wellformed_input{"qfqtkz9fivetst"};
        assert(v1::merge_edge_digits(wellformed_input) == 99);
    }

    {
        std::string wellformed_input{"asdfasdfsevenasdfasdf"};
        assert(v2::merge_edge_digits(wellformed_input) == 77);
    }

    {
        std::string wellformed_input{"three2seven7"};
        assert(v2::merge_edge_digits(wellformed_input) == 37);
    }

    {
        std::string wellformed_input{"1three2seven7"};
        assert(v2::merge_edge_digits(wellformed_input) == 17);
    }

    {
        std::string wellformed_input{"5threesevenasdfasdf"};
        assert(v2::merge_edge_digits(wellformed_input) == 57);
    }

    {
        std::string wellformed_input{"threesevenasdfasdf"};
        assert(v2::merge_edge_digits(wellformed_input) == 37);
    }

    {
        std::string wellformed_input{"threeonesevenasdfasdf"};
        assert(v2::merge_edge_digits(wellformed_input) == 37);
    }

    {
        std::string wellformed_input{"three8oneseven43asdfasdf"};
        assert(v2::merge_edge_digits(wellformed_input) == 33);
    }

    {
        std::string wellformed_input{"threone"};
        assert(v2::merge_edge_digits(wellformed_input) == 11);
    }

    {
        std::string wellformed_input{"23"};
        assert(v2::merge_edge_digits(wellformed_input) == 23);
    }
   
    {
        std::string wellformed_input{"2three"};
        assert(v2::merge_edge_digits(wellformed_input) == 23);
    }

    {
        std::string wellformed_input{"twothree"};
        assert(v2::merge_edge_digits(wellformed_input) == 23);
    } 
    
    {
        std::string wellformed_input{"two3"};
        assert(v2::merge_edge_digits(wellformed_input) == 23);
    }

    {
        std::string wellformed_input{"two"};
        assert(v2::merge_edge_digits(wellformed_input) == 22);
    }

    {
        std::string wellformed_input{"2"};
        assert(v2::merge_edge_digits(wellformed_input) == 22);
    }

    {
        std::string wellformed_input{"five2seven"};
        assert(v2::merge_edge_digits(wellformed_input) == 57);
    }


    {
        std::string wellformed_input{"5twoseven"};
        assert(v2::merge_edge_digits(wellformed_input) == 57);
    }


    {
        std::string wellformed_input{"five2seven"};
        assert(v2::merge_edge_digits(wellformed_input) == 57);
    }

    
    {
        std::string wellformed_input{"twothreefive"};
        assert(v2::merge_edge_digits(wellformed_input) == 25);
    }

    {
        std::string wellformed_input{"twothree5"};
        assert(v2::merge_edge_digits(wellformed_input) == 25);
    }

    {
        std::string wellformed_input{"235"};
        assert(v2::merge_edge_digits(wellformed_input) == 25);
    }


    {
        std::string wellformed_input{"23five"};
        assert(v2::merge_edge_digits(wellformed_input) == 25);
    }

    {
        std::string wellformed_input{"2three5"};
        assert(v2::merge_edge_digits(wellformed_input) == 25);
    }

    {
        std::string wellformed_input{"2threefive"};
        assert(v2::merge_edge_digits(wellformed_input) == 25);
    }

     {
        std::string wellformed_input{"two35"};
        assert(v2::merge_edge_digits(wellformed_input) == 25);
    }

    {
        std::string wellformed_input{"two3five"};
        assert(v2::merge_edge_digits(wellformed_input) == 25);
    }

    {
        std::string wellformed_input{"msgbxbbtb3pnlnjsixthreefoureightwobm"};
        assert(v2::merge_edge_digits(wellformed_input) == 32);
    }

    {
        std::string wellformed_input{"5vn"};
        assert(v2::merge_edge_digits(wellformed_input) == 55);
    }

    {
        std::string wellformed_input{"cvvpszdheight6"};
        assert(v2::merge_edge_digits(wellformed_input) == 86);
    }

    {
        std::string wellformed_input{"1twoeightsix"};
        assert(v2::merge_edge_digits(wellformed_input) == 16);
    }

    {
        std::string wellformed_input{"x8"};
        assert(v2::merge_edge_digits(wellformed_input) == 88);
    }

    {
        std::string wellformed_input{"6four1fcmhbpmbknkpxthpcthreesevenonethree"};
        std::cout <<  v2::merge_edge_digits(wellformed_input)  << " <--\n"; 
        assert(v2::merge_edge_digits(wellformed_input) == 63);
    }

    std::cout << "Tests passed!" << std::endl;
}
