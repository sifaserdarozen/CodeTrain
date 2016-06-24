/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

// standard libraries
#include <vector>
#include <algorithm>    // for std::equal

// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

extern int solution(int X, int Y, int D);

TEST_CASE( "Codility tests cases", "[solution]"  )
{
    SECTION( "check for X= 10, Y=85, D=30 default test case " )
    {
        REQUIRE( 3 == solution(10, 85, 30));
    }
}

TEST_CASE( "extreme tests", "[solution]" )
{
    SECTION( "maximum range maximum step test" )
    {
        REQUIRE( 1 == solution(1, 1000000000, 1000000000));
    }
    
    SECTION( "maximum range minimum step test" )
    {
        REQUIRE( 999999999 == solution(1, 1000000000, 1));
    }
} 
