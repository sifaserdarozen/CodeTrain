// Compute Complexity O(NM)
// Space Complexity O(1)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func isSameTree(nodeA, nodeB *TreeNode) bool {
    switch {
        case (nil == nodeA && nil != nodeB) || (nil != nodeA && nil == nodeB):

            return false
        case nil == nodeA && nil == nodeB:
            return true
        default:
            return nodeA.Val == nodeB.Val && isSameTree(nodeA.Left, nodeB.Left) && isSameTree(nodeA.Right, nodeB.Right)
    }
}

func isSubtree(root *TreeNode, subRoot *TreeNode) bool {
    if nil == subRoot {
        return true
    }
    if nil == root {
        return false
    }

    if isSameTree(root, subRoot) {
        return true
    }

    return isSubtree(root.Left, subRoot) || isSubtree(root.Right, subRoot)
}