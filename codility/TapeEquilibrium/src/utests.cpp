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
    SECTION( "check for vector A = [] " )
    {
        std::vector<int> A = {3, 1, 2, 4, 3};
        REQUIRE( 1 == solution(A));
    }
}

TEST_CASE( "extreme tests", "[solution]" )
{
    SECTION( "minimum number of elements" )
    {
        std::vector<int> A = {1, -1};
        REQUIRE( 2 == solution(A));
    }
} 
