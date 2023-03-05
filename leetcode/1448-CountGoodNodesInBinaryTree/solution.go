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

 import "math"

 func sumGoodNodes(root *TreeNode, max int) int {
	 if nil == root {
		 return 0
	 }
 
	 sum := 0
	 if root.Val >= max {
		 sum = 1
		 max = root.Val
	 }
 
	 return sum + sumGoodNodes(root.Left, max) + sumGoodNodes(root.Right, max)
 }
 func goodNodes(root *TreeNode) int {
	 return sumGoodNodes(root, math.MinInt)
 }