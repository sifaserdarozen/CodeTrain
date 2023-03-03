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
 func isSameTree(p *TreeNode, q *TreeNode) bool {
    switch {
        case nil != p && nil != q:
            return p.Val == q.Val && isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
        case nil == p && nil == q:
            return true
        default:
            return false
    }      
}