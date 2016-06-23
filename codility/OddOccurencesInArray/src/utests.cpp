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
    SECTION( "check for 5 element test array [9, 3, 9, 3, 9, 7, 9] " )
    {
        std::vector<int> A = {9, 3, 9, 3, 9, 7, 9};
        REQUIRE( 7 == solution(A));
    }
}

TEST_CASE( "extreme tests", "[solution]" )
{
    SECTION( "small vector test" )
    {
        std::vector<int> A = {55};
        REQUIRE( 55 == solution(A));
    }
    
    SECTION( "extreme value test" )
    {
        std::vector<int> A = {1, 1000000000, 1};
        REQUIRE( 1000000000 == solution(A));
    }
} 
