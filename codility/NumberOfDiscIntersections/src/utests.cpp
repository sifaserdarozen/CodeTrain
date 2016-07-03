/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

#include <vector>
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

extern int solution(std::vector<int> &A);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility test" )
    {
        std::vector<int> A = {1, 5, 2, 1, 4, 0};
        REQUIRE( 11 == solution(A));
    }
}

TEST_CASE( "Extra tests cases", "[solution]"  )
{
    SECTION( "three same element set" )
    {
        std::vector<int> A = {1, 1, 1};
        REQUIRE( 3 == solution(A));
    }
    SECTION( "alternating small set" )
    {
        std::vector<int> A = {1, 0, 1, 0, 1};
        REQUIRE( 6 == solution(A));
    }
    SECTION( "extreme radius set" )
    {
        std::vector<int> A = {1, 2147483647, 0};
        REQUIRE( 2 == solution(A));
    }
    SECTION( "non intersecting set" )
    {
        std::vector<int> A = {0, 0, 0};
        REQUIRE( 0 == solution(A));
    }
}