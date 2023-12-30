#pragma once

#include <iomanip>

const bool kIsDebugOn = true;
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define DEBUG_PRINT(MSG) if(kIsDebugOn){ std::cout << "[" << std::right << std::setw(16) << __FILE__ << ":" << std::left << std::setw(4) << __LINE__ << "] " << BOLDWHITE << MSG << RESET << std::endl;}
#define DEBUG_PRINT_TESTNAME(MSG) DEBUG_PRINT(RESET << YELLOW << MSG)
