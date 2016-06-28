/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

#include <vector>
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

extern int solution(std::vector<int> &A, std::vector<int> &B);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility test" )
    {
        std::vector<int> A = {4, 3, 2, 1, 5};
        std::vector<int> B = {0, 1, 0, 0, 0};
        REQUIRE( 2 == solution(A, B));
    }
}

TEST_CASE( "Small number of fish tests", "[solution]"  )
{
    SECTION( "one fish going up" )
    {
        std::vector<int> A = {4};
        std::vector<int> B = {0};
        REQUIRE( 1 == solution(A, B));
    }
    SECTION( "one fish going down" )
    {
        std::vector<int> A = {4};
        std::vector<int> B = {1};
        REQUIRE( 1 == solution(A, B));
    }
    SECTION( "two fish going up" )
    {
        std::vector<int> A = {4, 1};
        std::vector<int> B = {0, 0};
        REQUIRE( 2 == solution(A, B));
    }
    SECTION( "one fish going down" )
    {
        std::vector<int> A = {4, 1};
        std::vector<int> B = {1, 1};
        REQUIRE( 2 == solution(A, B));
    }
    SECTION( "one fish going down" )
    {
        std::vector<int> A = {1, 4};
        std::vector<int> B = {0, 1};
        REQUIRE( 2 == solution(A, B));
    }
    SECTION( "one fish going down" )
    {
        std::vector<int> A = {1, 4};
        std::vector<int> B = {1, 0};
        REQUIRE( 1 == solution(A, B));
    }
    SECTION( "codility extra small set" )
    {
        std::vector<int> A = {0, 1};
        std::vector<int> B = {1, 1};
        REQUIRE( 2 == solution(A, B));
    }
}