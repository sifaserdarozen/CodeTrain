// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
#include <iostream>

/** @brief Binary tree with value, and pointers to left and right branches
 */
struct tree {
    int x;
    tree * l;
    tree * r;
    tree(int a_x = 0, tree* a_l = NULL, tree* a_r =NULL): x(a_x), l(a_l), r(a_r) {};
};

/** @brief function returns the depth of a bibary tree
 * 
 *  Function returns depth of a binary tree.
 *  If tree has only root value, depth is defined to be 1
 *  If there is no tree at all (T is null), then depth is -1
 * 
 *  @param T binary tree
 *  @retun depth of binary tree
 */
int solution(tree * T) {
    // write your code in C++11 (g++ 4.8.2)
    // do sanith checks
    if (NULL == T)
        return -1;
    if ((NULL == T->l) && (NULL == T->r))
        return 0;
    else 
        return 1 + std::max(solution(T->l), solution(T->r));
}