/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>

extern std::vector<int> solution(int N, std::vector<int> &P, std::vector<int> &Q);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility sampe test" )
    {
        std::vector<int> P = {1, 4, 16};
        std::vector<int> Q = {26, 10, 20};
        std::vector<int> result_reference ={10, 4, 0};
        REQUIRE( result_reference == solution(26, P, Q));
    }
}

TEST_CASE( "Extra tests", "[solution]"  )
{
    SECTION( "single element test " )
    {
        std::vector<int> P = {1};
        std::vector<int> Q = {1};
        std::vector<int> result_reference ={0};
        REQUIRE( result_reference == solution(1, P, Q));
    }
}