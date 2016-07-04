/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

extern int solution(int N);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility test" )
    {
        REQUIRE( 22 == solution(30));
    }
}

TEST_CASE( "Extra tests case", "[solution]"  )
{
    SECTION( "unit area rectangle" )
    {
        REQUIRE( 4 == solution(1));
    }
}