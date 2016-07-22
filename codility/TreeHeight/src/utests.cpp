/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

struct tree {
    int x;
    tree * l;
    tree * r;
    tree(int a_x = 0, tree* a_l = NULL, tree* a_r =NULL): x(a_x), l(a_l), r(a_r) {};
};

extern int solution(tree * T);

TEST_CASE( "Sanity test cases", "[solution]"  )
{
    // 2 for (5, (3, (20, None, None), (21, None, None)), (10, (1, None, None), None))
    SECTION( "codility test case" )
    {
        tree T_20(20);
        tree T_21(21);
        tree T_3(3, &T_20, &T_21);
        tree T_1(1);
        tree T_10(10, &T_1, NULL);
        tree T(5, &T_3, &T_10);
        REQUIRE( 2 == solution(&T));
    }     
    SECTION( "null root" )
    {
        tree* T = NULL;
        REQUIRE( -1 == solution(T));
    }
    SECTION( "single root" )
    {
        tree T(10);
        REQUIRE( 0 == solution(&T));
    }
}

