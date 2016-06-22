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

extern std::vector<int> solution(std::vector<int> &A, int K);

TEST_CASE( "Codility tests cases", "[solution]"  )
{
    std::vector<int> A = {3, 8, 9, 7, 6};
    SECTION( "check for N = 1 " )
    { 
        std::vector<int> reference = {6, 3, 8, 9, 7};
        std::vector<int> shifted_A = solution(A, 1);
        REQUIRE( reference == shifted_A);
    }
    
    SECTION( "check for N = 3 " )
    {
        std::vector<int> reference = {9, 7, 6, 3, 8};
        std::vector<int> shifted_A = solution(A, 3);
        REQUIRE( reference == shifted_A);
    }
}

TEST_CASE( "Small vector test", "[solution]" )
{
    std::vector<int> A = {3, -2};
    SECTION( "check for N = 1" )
    {
        std::vector<int> reference = {-2, 3};
        std::vector<int> shifted_A = solution(A, 1);
        REQUIRE( reference == shifted_A);
    }
    
    SECTION( "check for N = 2" )
    {
        std::vector<int> reference = {3, -2};
        std::vector<int> shifted_A = solution(A, 2);
        REQUIRE( reference == shifted_A);    }
} 
