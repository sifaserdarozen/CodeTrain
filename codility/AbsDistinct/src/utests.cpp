/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>

extern int solution(std::vector<int> &A);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility sampe test" )
    {
        std::vector<int> A = {-5, -3, -1, 0, 3, 6};
        REQUIRE( 5 == solution(A));
    }
}

TEST_CASE( "Extra test cases", "[solution]"  )
{
    SECTION( "codility sampe test" )
    {
        std::vector<int> A = {-2, -2, 2, 2};
        REQUIRE( 1 == solution(A));
    }
}