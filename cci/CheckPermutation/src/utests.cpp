/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <utility>
#include <string>
#include <vector>

#include <iostream>

extern bool checkPermutation(const std::string& strA, const std::string& strB);
extern bool checkPermutationWithoutContainer(std::string strA, std::string strB);

TEST_CASE( "tests case", "[solution]"  )
{
    std::vector<std::pair<std::pair<std::string, std::string>, bool>> testStrings{ { {"abc", "abc"}, true} , { {"A", "A"}, true }, { {"Abv", "Ab"}, false}, { {"aboOaa", "aabaOo"}, true }, {{"aliveli", "veliilb" }, false}, { {"ii", "ii"}, true }, { {"aAbBcCdDeEfFgGhHa", "abcdeABCDEfFGghaH"}, true} };
    
    SECTION( "solution with extra container" )
    {
		for (const auto& s : testStrings) {
            REQUIRE( s.second == checkPermutation(s.first.first, s.first.second));
        }    
    }
    
    SECTION( "solution without using extra container" )
    {
		for (const auto& s : testStrings) {
            REQUIRE( s.second == checkPermutationWithoutContainer(s.first.first, s.first.second));
        }    
    }
}
