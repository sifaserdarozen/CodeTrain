/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

extern int solution(std::string &S);

TEST_CASE( "Codility tests case", "[solution]"  )
{
    SECTION( "codility properly nested string test" )
    {
        std::string S("{[()()]}");
        REQUIRE( 1 == solution(S));
    }
    SECTION( "codility non properly nested string test" )
    {
        std::string S("([)()]");
        REQUIRE( 0 == solution(S));
    }
}

TEST_CASE( "Small number of fish tests", "[solution]"  )
{
    SECTION( "empty string" )
    {
        std::string S;
        REQUIRE( 1 == solution(S));
    }
    SECTION( "failing small set" )
    {
        std::string S("[");
        REQUIRE( 0 == solution(S));
    }
    SECTION( "failing small set" )
    {
        std::string S("][");
        REQUIRE( 0 == solution(S));
    }
    SECTION( "passing alternate test" )
    {
        std::string S("()[]{}({[]}){([])}");
        REQUIRE( 1 == solution(S));
    }
}