/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

// standard libraries
#include "iostream"

// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

extern int solution(int N);

TEST_CASE( "Sanity check", "[solution]" )
{
    SECTION( "check for N = 1 " )
    {
        int max_gap = solution(1);
        REQUIRE( 0 == max_gap );
    }
    
    SECTION( "check for N = 3 " )
    {
        int max_gap = solution(3);
        REQUIRE( 0 == max_gap );
    }
}
TEST_CASE( "Codility tests cases", "[solution]" )
{
    SECTION( "check for N = 15" )
    {
        int max_gap = solution(15);
        REQUIRE( 0 == max_gap );
    }
    
    SECTION( "check for N = 20" )
    {
        int max_gap = solution(20);
        REQUIRE( 1 == max_gap );
    }

    SECTION( "check for N = 529" )
    {
        int max_gap = solution(529);
        REQUIRE( 4 == max_gap );
    }

    SECTION( "check for N = 9" )
    {
        int max_gap = solution(9);
        REQUIRE( 2 == max_gap );
    }

    SECTION( "check for N = 1041" )
    {
        int max_gap = solution(1041);
        REQUIRE( 5 == max_gap );
    }
} 
