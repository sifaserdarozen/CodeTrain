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

 func isValid(root *TreeNode, min, max int64) bool {
	 if nil == root {
		 return true
	 }
 
	 val := int64(root.Val)
	 if val < max && val > min {
		 return isValid(root.Left, min, val) && isValid(root.Right, val, max)
	 } else {
		 return false
	 }
 }
 
 func isValidBST(root *TreeNode) bool {
	 return isValid(root, math.MinInt64, math.MaxInt64)
 }