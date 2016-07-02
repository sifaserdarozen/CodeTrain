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
    SECTION( "codility test" )
    {
        std::vector<int> A = {3, 2, -6, 4, 0};
        REQUIRE( 5 == solution(A) );
    }
}

TEST_CASE( "Minunum vector tests", "[solution]"  )
{
    SECTION( "single element vector vector " )
    {
        std::vector<int> A = {-2};
        REQUIRE( -2 == solution(A) );
    }
    
    SECTION( "two element vector " )
    {
        std::vector<int> A = {-2, -1};
        REQUIRE( -1 == solution(A) );
    }
}
