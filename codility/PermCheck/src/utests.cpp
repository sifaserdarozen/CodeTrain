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

TEST_CASE( "Codility tests cases", "[solution]"  )
{
    SECTION( "check for passing permutation vector A = [] " )
    {
        std::vector<int> A = {4, 1, 3, 2};
        REQUIRE( 1 == solution(A));
    }
    SECTION( "check for failing permutation vector A = [] " )
    {
        std::vector<int> A = {4, 1, 3};
        REQUIRE( 0 == solution(A));
    }
}

TEST_CASE( "extreme tests", "[solution]" )
{
    SECTION( "minimum number of elements with positive result" )
    {
        std::vector<int> A = {1};
        REQUIRE( 1 == solution(A));
    }
    SECTION( "minimum number of elements with negative result" )
    {
        std::vector<int> A = {2};
        REQUIRE( 0 == solution(A));
    }
    SECTION( "check for passing permutation vector with bigger element than vector size" )
    {
        std::vector<int> A = {4, 1, 5, 2};
        REQUIRE( 0 == solution(A));
    }
    SECTION( "check for passing permutation vector with dublicate elements" )
    {
        std::vector<int> A = {4, 1, 5, 2, 2};
        REQUIRE( 0 == solution(A));
    }
} 
