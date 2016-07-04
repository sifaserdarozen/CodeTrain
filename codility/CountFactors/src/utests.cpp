/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

extern int solution(int N);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility test, factors of 24 are: 1, 2, 3, 4, 6, 8, 12, 24" )
    {
        REQUIRE( 8 == solution(24));
    }
}

TEST_CASE( "Extra tests case", "[solution]"  )
{
    SECTION( "minimum factor test, factor of 1 is only himself" )
    {
        REQUIRE( 1 == solution(1));
    }
    SECTION( "prime number test, factors of 2 are: 1, 2 " )
    {
        REQUIRE( 2 == solution(2));
    }
    SECTION( "square number test, factors of 36 are: 1, 2, 3, 4, 6, 9, 12, 18, 36" )
    {
        REQUIRE( 9 == solution(36));
    }
}