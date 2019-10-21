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

extern bool isUnique(const std::string& str);
extern bool isUniqueWithoutContainer(std::string str);

TEST_CASE( "tests case", "[solution]"  )
{
    std::vector<std::pair<std::string, bool>> testStrings{ {"abc", true}, {"A", true}, {"", true}, {"aboO", true}, {"aliveli", false}, {"ii", false}, {"aAbBcCdDeEfFgGhHa", false} };
    
    SECTION( "solution with extra container" )
    {
		for (const auto& s : testStrings) {
            REQUIRE( s.second == isUnique(s.first));
        }    
    }
    
    SECTION( "solution without using extra container" )
    {
		for (const auto& s : testStrings) {
            REQUIRE( s.second == isUniqueWithoutContainer(s.first));
        }    
    }
}
