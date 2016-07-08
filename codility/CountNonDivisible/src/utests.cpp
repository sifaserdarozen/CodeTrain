/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>

extern std::vector<int> solution(std::vector<int> &A);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility sampe test" )
    {
        std::vector<int> A = {3, 1, 2, 3, 6};
        std::vector<int> result_reference ={2, 4, 3, 2, 0};
        REQUIRE( result_reference == solution(A));
    }
}

TEST_CASE( "Extra tests", "[solution]"  )
{
    SECTION( "single element test " )
    {
        std::vector<int> A = {2};
        std::vector<int> result_reference ={0};
        REQUIRE( result_reference == solution(A));
    }
}