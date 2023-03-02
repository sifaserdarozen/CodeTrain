package solution

// Compute Complexity O(N)
// Space Complexity O(1)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func getMax(a int, b int) int {
    if a < b {
        return b
    } else {
        return a
    }
}

func maxDepth(root *TreeNode) int {
    if nil == root {
        return 0
    }

    return 1 + getMax(maxDepth(root.Left), maxDepth(root.Right))
}