/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>

extern std::vector<int> solution(std::vector<int> &A, std::vector<int> &B);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility sampe test" )
    {
        std::vector<int> A = {4, 4, 5, 5, 1};
        std::vector<int> B = {3, 2, 4, 3, 1};
        std::vector<int> reference = {5, 1, 8, 0, 1};
        REQUIRE( reference == solution(A, B));
    }
}
