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
    SECTION( "get theminimum value of 5" )
    {
        std::vector<int> A = {1, 3, 6, 4, 1, 2};
        REQUIRE( 5 == solution(A));
    }
}

TEST_CASE( "extreme tests", "[solution]" )
{
    SECTION( "minimum number of elements with positive result" )
    {
        std::vector<int> A = {-2147483648, 2147483647};
        REQUIRE( 1 == solution(A));
    }
} 
