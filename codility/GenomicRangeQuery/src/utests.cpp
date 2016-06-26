/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

#include <string>
#include <vector>
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

extern std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility test" )
    {
        std::string S("CAGCCTA");
        std::vector<int> P = {2, 5, 0};
        std::vector<int> Q = {4, 5, 6};
        std::vector<int> reference_result = {2, 4, 1};
        REQUIRE( reference_result == solution(S, P, Q));
    }
}

TEST_CASE( "do some sanity tests", "[solution]"  )
{
    SECTION( "codility test" )
    {
        std::string S("AGCCTA");
        std::vector<int> P = {0, 0, 1};
        std::vector<int> Q = {0, 1, 4};
        std::vector<int> reference_result = {1, 1, 2};
        REQUIRE( reference_result == solution(S, P, Q));
    }
}
