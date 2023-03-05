// Compute Complexitx O(N)
// Space Complexity O(log(N))

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 import "math"

 func getMax(vals ...int) int {
	 max := vals[0]
	 for _, v := range(vals) {
		 if v > max {
			 max = v
		 }
	 }
	 return max
 }
 
 func getMaxPath(root *TreeNode)(int, int) {
	 if nil == root {
		 return math.MinInt, 0
	 }
 
	 leftPath, leftDepth := getMaxPath(root.Left)
	 rightPath, rightDepth := getMaxPath(root.Right)
 
	 depth := getMax(root.Val, root.Val + getMax(leftDepth, rightDepth))
	 path := getMax(root.Val, leftPath, rightPath, root.Val + leftDepth, root.Val + rightDepth, root.Val + leftDepth + rightDepth)
 
	 return path, depth
 }
 func maxPathSum(root *TreeNode) int {
	 maxPath, _ := getMaxPath(root)
	 return maxPath
 }