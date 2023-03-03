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
    if a > b {
        return a
    } else {
        return b
    }
}

func isNodeInBalance(left int, right int) bool {
    diff := left - right
    if diff < 0 {
        diff *= -1
    }
    return diff <= 1
}

// return balance status and depth of node
func getBalance(node *TreeNode)(bool, int) {
    if nil == node {
        return true, 0
    }

    leftBalance, leftDepth := getBalance(node.Left)
    rightBalance, rightDepth := getBalance(node.Right)

    balanced := leftBalance && rightBalance && isNodeInBalance(leftDepth, rightDepth)
    depth := 1 + getMax(leftDepth, rightDepth)

    return balanced, depth
} 

func isBalanced(root *TreeNode) bool {
    balanced, _ := getBalance(root)
    return balanced
}