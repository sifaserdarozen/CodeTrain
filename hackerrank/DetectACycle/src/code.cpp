#include <set>

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
*/
    struct Node {
        int data;
        struct Node* next;
    };


/** Function detecting loops in linked list
 *
 *  Function detects loop inlinked list with keeping each node 
 *  address instd::set and comparing new pointers with backlog
 *
 *  Time complexity is O(nlogn)
 *  Space complexity is O(n)
 *
 *  @param linked list head
 *  @return presence of loop or not in boolean
 */
bool has_cycle(Node* head) {
    std::set<Node*> node_history;
    unsigned int history_size = 0;
    
    while(head)
    {
        node_history.insert(head);
        if (history_size == node_history.size())
            return true;
        
        history_size++;
        head = head->next;
    }
    
    return false;
}

