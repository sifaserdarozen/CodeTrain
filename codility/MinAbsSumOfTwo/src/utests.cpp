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
    SECTION( "codility small test" )
    {
        std::vector<int> A = {1, 5, 2, -2};
        REQUIRE( 0 == solution(A));
    }
}

TEST_CASE( "Codility extra test", "[solution]"  )
{
    SECTION( "codility extra test" )
    {
        std::vector<int> A = {3, 3, 3, 4, 5};
        REQUIRE( 0 == solution(A));
    }
}
