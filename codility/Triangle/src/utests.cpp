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
    SECTION( "codility test that includes a triangle" )
    {
        std::vector<int> A = {10, 2, 5, 1, 8, 20};
        REQUIRE( 1 == solution(A));
    }
    SECTION( "codility test that does not include a triangle" )
    {
        std::vector<int> A = {10, 50, 5, 1};
        REQUIRE( 0 == solution(A));
    }
}

TEST_CASE( "Extra test cases", "[solution]"  )
{
    SECTION( "minimum set that includes a triangle" )
    {
        std::vector<int> A = {3, 5, 4};
        REQUIRE( 1 == solution(A));
    }
    SECTION( "test negative numbers" )
    {
        std::vector<int> A = {-3, -4, -5};
        REQUIRE( 0 == solution(A));
    }
    SECTION( "test maximums" )
    {
        std::vector<int> A = {2147483647, 2147483647, 1};
        REQUIRE( 1 == solution(A));
    }
}
