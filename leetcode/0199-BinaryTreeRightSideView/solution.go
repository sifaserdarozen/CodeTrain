// Compute Complexity O(N)
// Space Complexity O(log(N))

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func getRightSide(root *TreeNode, level int, res *([]int)) {
    if nil == root {
        return
    }
    
    // we put item at level only if there was not
    // already (from a more right side)
    if len(*res) == level {
        *res = append(*res, root.Val)
    }

    // explore right branch first
    getRightSide(root.Right, level + 1, res)
    getRightSide(root.Left, level + 1, res)
}
func rightSideView(root *TreeNode) []int {
    res := []int{}
    getRightSide(root, 0, &res)
    return res
}