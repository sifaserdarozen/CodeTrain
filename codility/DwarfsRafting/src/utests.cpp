/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>

extern int solution(int N, std::string &S, std::string &T);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility small test" )
    {
        std::string S = "1B 1C 4B 1D 2A";
        std::string T = "3B 2D";
        REQUIRE( 6 == solution(4, S, T));
    }
}

TEST_CASE( "Extra test cases", "[solution]"  )
{
    SECTION( "fail test" )
    {
        std::string S = "1A";
        std::string T = "2B";
        REQUIRE( -1 == solution(2, S, T));
    }
    SECTION( "pass test" )
    {
        std::string S = "1A";
        std::string T = "2A";
        REQUIRE( 1 == solution(2, S, T));
    }
    SECTION( "a large test" )
    {
        std::string S = "1B 14B 20Z 1Y";
        std::string T = "3B 2D";
        REQUIRE( 670 == solution(26, S, T));
    }
}