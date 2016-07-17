/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>

extern int solution(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility sampe test" )
    {
        std::vector<int> A = {1, 4, 5, 8};
        std::vector<int> B = {4, 5, 9, 10};
        std::vector<int> C = {4, 6, 7, 10, 2};
        REQUIRE( 4 == solution(A, B, C));
    }
}

TEST_CASE( "extra tests case", "[solution]"  )
{
    SECTION( "some random array test" )
    {
        std::vector<int> A = {1, 4, 5, 8, 4, 6, 8, 12, 5, 7, 8, 3};
        std::vector<int> B = {4, 5, 9, 10, 9, 8, 9, 16, 7, 23, 10, 3};
        std::vector<int> C = {4, 6, 7, 10, 2, 20, 3, 8, 13, 6, 6, 1};
        REQUIRE( 9 == solution(A, B, C));
    }
    
    SECTION( "all planks are points" )
    {
        std::vector<int> A = {1, 2, 5, 3, 2, 9678, 8, 4};
        std::vector<int> B = {1, 2, 5, 3, 2, 9678, 8, 4};
        std::vector<int> C = {4, 9678, 9679, 8, 4, 2, 3, 5, 1, 5, 9, 125};
        REQUIRE( 9 == solution(A, B, C));
    }
    SECTION( "single element pass" )
    {
        std::vector<int> A = {2};
        std::vector<int> B = {2};
        std::vector<int> C = {2};
        REQUIRE( 1 == solution(A, B, C));
    }
    SECTION( "single element fail" )
    {
        std::vector<int> A = {4};
        std::vector<int> B = {4};
        std::vector<int> C = {5};
        REQUIRE( -1 == solution(A, B, C));
    }
}
