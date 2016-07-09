/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>

extern int solution(std::vector<int> &A, std::vector<int> &B);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility sampe test" )
    {
        std::vector<int> A = {15,10, 3};
        std::vector<int> B = {75, 30, 5};
        REQUIRE( 1 == solution(A, B));
    }
}

TEST_CASE( "Extra tests cases", "[solution]"  )
{
    SECTION( "small vector test" )
    {
        std::vector<int> A = {1};
        std::vector<int> B = {1};
        REQUIRE( 1 == solution(A, B));
    }
    SECTION( "same vectors test" )
    {
        std::vector<int> A = {2, 3};
        std::vector<int> B = {2, 3};
        REQUIRE( 2 == solution(A, B));
    }
}