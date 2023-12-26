#pragma once

#include <set>
#include <list>
#include <iomanip>
#include <sstream>

const bool kIsDebugOn = true;
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define DEBUG_PRINT(MSG) if(kIsDebugOn){ std::cout << "[" << std::right << std::setw(16) << __FILE__ << ":" << std::left << std::setw(4) << __LINE__ << "] " << BOLDWHITE << MSG << RESET << std::endl;}
#define DEBUG_PRINT_TESTNAME(MSG) DEBUG_PRINT(RESET << YELLOW << MSG)

int count_guessed_numbers(const std::set<int>& winning_numbers, std::list<int> scratched_numbers);
int calculate_round_points(const std::set<int>& winning_numbers, std::list<int> scratched_numbers);
std::set<int> extract_winning_numbers(std::string input);
std::list<int>  extract_scratched_numbers(std::string input);
