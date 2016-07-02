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
        std::vector<int> A = {3, 2, 6, -1, 4, 5, -1, 2};
        REQUIRE( 17 == solution(A) );
    }
}

TEST_CASE( "Minunum vector tests", "[solution]"  )
{
    SECTION( "Three element minumum vector " )
    {
        std::vector<int> A = {3, 2, 6};
        REQUIRE( 0 == solution(A) );
    }
    
    SECTION( "Four element minumum vector " )
    {
        std::vector<int> A = {3, 2, 4, 6};
        REQUIRE( 4 == solution(A) );
    }
}

TEST_CASE( "Negative element tests", "[solution]"  )
{
    SECTION( "Three element minumum vector " )
    {
        std::vector<int> A = {-3, -2, -6};
        REQUIRE( 0 == solution(A) );
    }
    
    SECTION( "Four element minumum vector " )
    {
        std::vector<int> A = {-3, 2, -4, -6};
        REQUIRE( 2 == solution(A) );
    }
    
    SECTION( "Five element all negative vector " )
    {
        std::vector<int> A = {-3, -2, -4, -6, 3};
        REQUIRE( 0 == solution(A) );
    }
}


