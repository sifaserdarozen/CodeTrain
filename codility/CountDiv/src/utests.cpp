/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

extern int solution(int A, int B, int K);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility test" )
    {
        REQUIRE( 3 == solution(6, 11, 2));
    }
}

TEST_CASE( "Some sanity tests", "[solution]"  )
{
    SECTION( "start index is zero" )
    {
        REQUIRE( 6 == solution(0, 11, 2));
    }
    SECTION( "start and end index is zero" )
    {
        REQUIRE( 1 == solution(0, 0, 2));
    }
    SECTION( "start and end index is zero" )
    {
        REQUIRE( 0 == solution(1, 1, 11));
    }
    SECTION( "same start and end with single division" )
    {
        REQUIRE( 1 == solution(10, 10, 2));
    }
    SECTION( "same start and end with no division" )
    {
        REQUIRE( 0 == solution(11, 11, 2));
    }
    SECTION( "divisor is bigger than range" )
    {
        REQUIRE( 0 == solution(3, 11, 12));
    }
}
