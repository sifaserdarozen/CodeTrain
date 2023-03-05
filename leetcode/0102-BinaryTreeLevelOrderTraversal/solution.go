// Compute Complexity O(N)
// Space Complexits O(log(N))

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func getLevelOrder(root *TreeNode, level int, res *([][]int)) {
    // exit condition for the recursion
    if nil == root {
        return
    }

    // put empty slice for the missing levels
    for len(*res) <= level {
        *res = append(*res, []int{})
    }

    // put the value to its level
    (*res)[level] = append((*res)[level], root.Val)

    // continue with subtrees
    getLevelOrder(root.Left, level + 1, res)
    getLevelOrder(root.Right, level + 1, res)
}

func levelOrder(root *TreeNode) [][]int {
    res := make([][]int, 0)
    getLevelOrder(root, 0, &res)
    return res
}