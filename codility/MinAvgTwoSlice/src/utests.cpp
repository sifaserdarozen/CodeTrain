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
        std::vector<int> A = {4, 2, 2, 5, 1, 5, 8};
        REQUIRE( 1 == solution(A));
    }
}

TEST_CASE( "Extra test cases", "[solution]"  )
{
    SECTION( "minimum test" )
    {
        std::vector<int> A = {-1, -2};
        REQUIRE( 0 == solution(A));
    }
    SECTION( "same element test" )
    {
        std::vector<int> A = {-1, -2, -2, -2, -2};
        REQUIRE( 1 == solution(A));
    }
    SECTION( "Maximum elements test" )
    {
        std::vector<int> A = {-10000, 10000, -10000, -1, -10000};
        REQUIRE( 2 == solution(A));
    }
}