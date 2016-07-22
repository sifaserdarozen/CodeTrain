/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <string>

extern int solution(std::string &S);

TEST_CASE( "Sanity test cases", "[solution]"  )
{
    SECTION( "codility test case" )
    {
        std::string S = "racecar";
        REQUIRE( 3 == solution(S));
    }     
    SECTION( "empty string" )
    {
        std::string S = "";
        REQUIRE( -1 == solution(S));
    }
    SECTION( "single elementstring" )
    {
        std::string S = "x";
        REQUIRE( 0 == solution(S));
    }
}

