package solution

// Compute Complexity = O(N)
// Space Complexity = O(log(N))

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func getMax(nums ...int) int {
    max := nums[0]
    for _, v := range(nums) {
        if v > max {
            max = v
        }
    }
    return max
}

func getDiameter(node *TreeNode)(int, int) {
    if nil == node {
        return 0, 0
    }

    leftMaxDepth, leftMaxDiameter := getDiameter(node.Left)
    rightMaxDepth, rightMaxDiameter := getDiameter(node.Right)

    maxDepth := 1 + getMax(leftMaxDepth, rightMaxDepth)
    diameter := leftMaxDepth + rightMaxDepth
    maxDiameter := getMax(leftMaxDiameter, rightMaxDiameter, diameter)

    return maxDepth, maxDiameter    
}
func diameterOfBinaryTree(root *TreeNode) int {
    _, maxDiameter := getDiameter(root)
    return maxDiameter
}