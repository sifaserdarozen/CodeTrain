#include <iostream>
#include <climits>

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  
The Node struct is defined as follows:
*/

   struct Node {
      int data;
      Node* left;
      Node* right;
   };


bool NodeMinMax(Node* node, int& min, int& max)
{
    min = INT_MAX;
    max = INT_MIN;
    
    if (NULL != node->left)
    {
        int min_of_left_side = INT_MAX;
        int max_of_left_side = INT_MIN;
        if ((false == NodeMinMax(node->left, min_of_left_side, max_of_left_side)) || (max_of_left_side >= node->data))
            return false;
        else
            min = min_of_left_side;
    }
    else
        min = node->data;
     
    if (NULL != node->right)
    {
        int min_of_right_side = INT_MAX;
        int max_of_right_side = INT_MIN;
        if ((false == NodeMinMax(node->right, min_of_right_side, max_of_right_side)) || (min_of_right_side <= node->data))
            return false;
        else
            max = max_of_right_side;
    }
    else
        max = node->data;
    
    return true;
}

bool checkBST(Node* root) 
{
    if (NULL != root->left)
    {
        int min_of_left_side = INT_MAX;
        int max_of_left_side = INT_MIN;
        if ((false == NodeMinMax(root->left, min_of_left_side, max_of_left_side)) || (max_of_left_side >= root->data))
            return false;
    }
     
    if (NULL != root->right)
    {
        int min_of_right_side = INT_MAX;
        int max_of_right_side = INT_MIN;
        if ((false == NodeMinMax(root->right, min_of_right_side, max_of_right_side)) || (min_of_right_side <= root->data))
            return false;
    }
      
    return true;
}

