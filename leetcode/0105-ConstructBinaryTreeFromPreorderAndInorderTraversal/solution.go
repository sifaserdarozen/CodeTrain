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
 func buildTree(preorder []int, inorder []int) *TreeNode {
    return buildFromTree(preorder, inorder, 0, len(inorder) - 1, 0, len(inorder) - 1)
}

func buildFromTree(preorder, inorder []int, preStartIdx, preEndIdx, inStartIdx, inEndIdx int) *TreeNode {
    if preStartIdx > preEndIdx {
        return nil
    }

    idx := inStartIdx
    for inorder[idx] != preorder[preStartIdx]{
        idx++
    }

    leftInStartIdx := inStartIdx
    leftInEndIdx:= idx - 1
    rightInStartIdx:= idx + 1
    rightInEndIdx := inEndIdx

    leftPreStartIdx := preStartIdx + 1
    leftPreEndIdx := leftPreStartIdx + (leftInEndIdx - leftInStartIdx)
    rightPreStartIdx:= leftPreEndIdx + 1
    rightPreEndIdx := preEndIdx

    left := buildFromTree(preorder, inorder, leftPreStartIdx, leftPreEndIdx, leftInStartIdx, leftInEndIdx)
    right := buildFromTree(preorder, inorder, rightPreStartIdx, rightPreEndIdx, rightInStartIdx, rightInEndIdx)

    return &TreeNode{Val: preorder[preStartIdx], Left: left, Right: right}
}