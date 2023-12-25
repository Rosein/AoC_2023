#include "scratchcards.hpp"
#include <cmath>

int count_guessed_numbers(const std::set<int>& winning_numbers, std::list<int> scratched_numbers)
{
    return scratched_numbers.remove_if(
                   [&winning_numbers](int number)
                   {
                        return winning_numbers.contains(number);
                   });
}

int calculate_round_points(const std::set<int>& winning_numbers, std::list<int> scratched_numbers)
{
    auto guessed_no = count_guessed_numbers(winning_numbers,scratched_numbers);
    return std::pow(2, --guessed_no);
}