/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>

extern int solution(int K, int M, std::vector<int> &A);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility sampe test" )
    {
        std::vector<int> A = {2, 1, 5, 1, 2, 2, 2};
        REQUIRE( 6 == solution(3, 5, A));
    }
}
