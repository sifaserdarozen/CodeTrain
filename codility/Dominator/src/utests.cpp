/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>
#include <set>

extern int solution(std::vector<int> &A);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility test" )
    {
        std::vector<int> A = {3, 4, 3, 2, 3, -1, 3, 3};
        int index = solution(A);
        std::set<int> possible_solution = {0, 2, 4, 6, 7};
        REQUIRE( possible_solution.end() != possible_solution.find(index) );
    }
}
TEST_CASE( "Extra test cases", "[solution]"  )
{
    SECTION( "empty vector" )
    {
        std::vector<int> A ;
        int index = solution(A);
        std::set<int> possible_solution = {-1};
        REQUIRE( possible_solution.end() != possible_solution.find(index) );
    }
    SECTION( "single element vector" )
    {
        std::vector<int> A = {-3};
        int index = solution(A);
        std::set<int> possible_solution = {0};
        REQUIRE( possible_solution.end() != possible_solution.find(index) );
    }
    SECTION( "no dominator double element vector" )
    {
        std::vector<int> A = {4, 1};
        int index = solution(A);
        std::set<int> possible_solution = {-1};
        REQUIRE( possible_solution.end() != possible_solution.find(index) );
    }
    SECTION( "no dominator vector" )
    {
        std::vector<int> A = {-1, 0, 1};
        int index = solution(A);
        std::set<int> possible_solution = {-1};
        REQUIRE( possible_solution.end() != possible_solution.find(index) );
    }
}
