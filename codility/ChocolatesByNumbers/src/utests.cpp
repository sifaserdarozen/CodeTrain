/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

#include <vector>

extern int solution(int N, int M);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility sampe test" )
    {
        REQUIRE( 5 == solution(10, 4));
    }
}

TEST_CASE( "Extra tests", "[solution]"  )
{
    SECTION( "single element test" )
    {
        REQUIRE( 1 == solution(1, 1));
    }
    SECTION( "simple test" )
    {
        REQUIRE( 4 == solution(4, 5));
    }
    SECTION( "test with extreme values" )
    {
        REQUIRE( 4453 == solution(4453, 947853));
    }
    SECTION( "test with extreme values replaced" )
    {
        REQUIRE( 947853 == solution(947853, 4453));
    }
}