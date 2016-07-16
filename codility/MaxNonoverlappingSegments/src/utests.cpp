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
    SECTION( "codility small test" )
    {
        std::vector<int> A = {1, 3, 7, 9, 9};
        std::vector<int> B = {5, 6, 8, 9, 10};
        REQUIRE( 3 == solution(A, B));
    }
}