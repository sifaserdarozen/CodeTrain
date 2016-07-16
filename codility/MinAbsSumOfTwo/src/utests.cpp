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
        std::vector<int> A = {1, 4, -3};
        REQUIRE( 1 == solution(A));
    }
    
    SECTION( "codility bigger test" )
    {
        std::vector<int> A = {-8, 4, 5, -10, 3};
        REQUIRE( 3 == solution(A));
    }
}

TEST_CASE( "Extra tests cases", "[solution]"  )
{
    SECTION( "codility small test" )
    {
        std::vector<int> A = {9, 5, 3, 4, 6, 9};
        REQUIRE( 6 == solution(A));
    }
}

