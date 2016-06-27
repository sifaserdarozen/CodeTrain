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
        std::vector<int> A = {2, 1, 1, 2, 3, 1};
        REQUIRE( 3 == solution(A));
    }
}

TEST_CASE( "Extra test cases", "[solution]"  )
{
    SECTION( "minimum equal numbers" )
    {
        std::vector<int> A = {1, 1, 1};
        REQUIRE( 1 == solution(A));
    }
    SECTION( "test negative numbers" )
    {
        std::vector<int> A = {-3, -4, -5};
        REQUIRE( 3 == solution(A));
    }
    SECTION( "test maximums" )
    {
        std::vector<int> A = {1000000, 1, 999999};
        REQUIRE( 3 == solution(A));
    }
}
