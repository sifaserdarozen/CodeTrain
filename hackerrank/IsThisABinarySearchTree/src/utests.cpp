/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

#include <iostream>
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

struct Node {int data; Node* left; Node* right;};
extern bool checkBST(Node* root); 

TEST_CASE( "hackerrank tests case", "[solution]"  )
{
    Node a;
    a.data = 10; a.left = NULL; a.right = NULL;

    Node b;
    b.data = 5; b.left = NULL; b.right = NULL;

    Node c;
    c.data = 2; c.left = NULL; c.left = NULL;

    Node d;
    d.data = 6; c.left = NULL; c.right = NULL;

    Node e;
    e.data = 11; e.left = NULL; e.right = NULL;

    Node f;
    f.data= 3;f.left = NULL; f.right = NULL;

    SECTION( "single node test" )
    {
        REQUIRE( true == checkBST(&a) );
    }

    SECTION( "two node passing" )
    {
        a.right = &e;
        REQUIRE( true == checkBST(&a) );
    }

    SECTION( "a linked list with a loop" )
    {
        c.left = &f;
        REQUIRE( false == checkBST(&c) );
    }

    SECTION( "an unbalanced tree" )
    {
         a.left = &b;
         a.right = &e;
         b.right = &d;
         REQUIRE( true == checkBST(&a) );
    }

    SECTION( "a failing complex tree" )
    {
        a.left = &b;
        a.right = &e;
        b.right = &d;
        c.left = &f;
        b.left = &c;
        REQUIRE( false == checkBST(&a) );
    }
}

