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

extern std::vector<int> solution(int N, std::vector<int> &A);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility test" )
    {
        std::vector<int> A = {3, 4, 4, 6, 1, 4, 4};
        std::vector<int> reference_vector = {3, 2, 2, 4, 2};
        REQUIRE( reference_vector == solution(5, A));
    }
}
