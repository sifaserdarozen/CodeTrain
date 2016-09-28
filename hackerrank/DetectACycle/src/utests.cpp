/** @file utests.cpp
 *
 * Unit tests are performed with Catch v1.3.5
 * More information about catch may be seen at their site https://github.com/philsquared/Catch
 */

#include <iostream>
 
// 3rd party libraries
#define CATCH_CONFIG_MAIN    // provides creation of executable, should be above catch.hpp
#include "catch.hpp"

struct Node {int data; struct Node* next;};
extern bool has_cycle(Node* head);

TEST_CASE( "hackerrank tests case", "[solution]"  )
{
    Node a_node;
    Node b_node;
    Node c_node;
    Node d_node;
    Node e_node;

    Node* head = &a_node;
    a_node.next = &b_node;
    b_node.next = &c_node;
    c_node.next = &d_node;
    d_node.next = &e_node;
    e_node.next = NULL;

    SECTION( "null test that includes a triangle" )
    {
        bool res = has_cycle(NULL);
        REQUIRE( false == res);
    }

    SECTION( "a linked list without a loop" )
    {
        REQUIRE( false == has_cycle(head) );
    }

    SECTION( "a linked list with a loop" )
    {
        e_node.next = &b_node;
        REQUIRE( true == has_cycle(head) );
    }
}

