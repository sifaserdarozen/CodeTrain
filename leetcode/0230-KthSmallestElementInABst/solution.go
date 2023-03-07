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
 func kthSmallest(root *TreeNode, k int) int {
    counter := 1
    if v, ok := getKthSmallest(root, &counter, k); !ok {
        panic("This should not happen: Not Found")
    } else {
        return v
    }
}

// inorder traversal with increasing numberOfNodesVisited
func getKthSmallest(node *TreeNode, numberOfNodesVisited *int, k int) (int, bool) {
    if nil == node {
        return -1, false
    }

    if v, ok := getKthSmallest(node.Left, numberOfNodesVisited, k); ok {
        return v, ok
    }

    if *numberOfNodesVisited == k {
        return node.Val, true
    }
    (*numberOfNodesVisited)++

    return getKthSmallest(node.Right, numberOfNodesVisited, k)
}