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

extern int solution(std::vector<int> &A);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility test" )
    {
        std::vector<int> A = {0, 1, 0, 1, 1};
        REQUIRE( 5 == solution(A));
    }
}

TEST_CASE( "All cars heading same direction test"  )
{
    SECTION( "all cars heading east" )
    {
        std::vector<int> A = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        REQUIRE( 0 == solution(A));
    }
    SECTION( "all cars heading west" )
    {
        std::vector<int> A = {1, 1, 1, 1, 1, 1, 1, 1};
        REQUIRE( 0 == solution(A));
    }
}

TEST_CASE( "Minimum number of cars test"  )
{
    SECTION( "a car heading east" )
    {
        std::vector<int> A = {0};
        REQUIRE( 0 == solution(A));
    }
    SECTION( "a car heading west" )
    {
        std::vector<int> A = {1};
        REQUIRE( 0 == solution(A));
    }
}

TEST_CASE( "A car against the rest of the cars heading same direction test"  )
{
    SECTION( "a car going west that already past rest" )
    {
        std::vector<int> A = {1, 0, 0, 0, 0, 0, 0, 0, 0};
        REQUIRE( 0 == solution(A));
    }
    SECTION( "a car going east that that will cross 7" )
    {
        std::vector<int> A = {0, 1, 1, 1, 1, 1, 1, 1};
        REQUIRE( 7 == solution(A));
    }
    SECTION( "a car going west that will cross 8" )
    {
        std::vector<int> A = {0, 0, 0, 0, 0, 0, 0, 0, 1};
        REQUIRE( 8 == solution(A));
    }
    SECTION( "a car going east that already past rest" )
    {
        std::vector<int> A = {1, 1, 1, 1, 1, 1, 1, 0};
        REQUIRE( 0 == solution(A));
    }
}
