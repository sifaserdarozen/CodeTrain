/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>

extern int solution(std::vector<int> &A);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility test" )
    {
        std::vector<int> A = {23171, 21011, 21123, 21366, 21013, 21367};
        REQUIRE( 356 == solution(A) );
    }
}

TEST_CASE( "Minunum vector tests", "[solution]"  )
{
    SECTION( "zero element vector vector " )
    {
        std::vector<int> A = {};
        REQUIRE( 0 == solution(A) );
    }
    
    SECTION( "one element vector " )
    {
        std::vector<int> A = {3};
        REQUIRE( 0 == solution(A) );
    }
    
    SECTION( "two element negative gain vector " )
    {
        std::vector<int> A = {3, 2};
        REQUIRE( 0 == solution(A) );
    }
}
