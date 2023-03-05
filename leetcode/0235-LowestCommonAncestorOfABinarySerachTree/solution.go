// Compute Complexity O(N)
// Space complexity O(log(N))

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val   int
 *     Left  *TreeNode
 *     Right *TreeNode
 * }
 */

 func getAncestor(root, p, q *TreeNode) (ancestor *TreeNode, containsP bool, containsQ bool) {
    if nil == root {
        return nil, false, false
    }

    ancestorLeft, pLeft, qLeft := getAncestor(root.Left, p, q)
    ancestorRight, pRight, qRight := getAncestor(root.Right, p, q)

    switch {
        case nil != ancestorLeft:
            return ancestorLeft, false, false
        case nil != ancestorRight:
            return ancestorRight, false, false
        case (root == p || pLeft || pRight) && (root == q || qLeft || qRight):
            return root, false, false
        default:
            return nil, root == p || pLeft || pRight, root == q || qLeft || qRight
    }
}
func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	ancestor, _, _ := getAncestor(root, p, q)
    return ancestor
}