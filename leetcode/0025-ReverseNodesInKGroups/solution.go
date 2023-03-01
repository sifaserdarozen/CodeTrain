package solution

// compute complexity O(N)
// space complexity O(K)

// Test Cases
// [1], k = 1
// [1, 2], k = 1
// [1, 3], k = 2
// [1,2,3,4,5], k = 1
// [1,2,3,4,5], k = 2
// [1,2,3,4,5], k = 3

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// reverse items starting with head till tail (without including tail)
func reversePart(head *ListNode, tail *ListNode, prev *ListNode) *ListNode {
    for head != tail {
        nextHead := head.Next
        head.Next = prev
        prev = head
        head = nextHead
    }
    return prev
}

func reverseKGroup(head *ListNode, k int) *ListNode {
    borders := make([]*ListNode, 0)

    // find chunk borders, each seperated with k items
    cntr := 0
    for ptr := head; nil != ptr; ptr = ptr.Next {
        if 0 == cntr % k {
            borders = append(borders, ptr)
        }
        cntr++
    }

    // if we have k items at the end add nullptr as well
    if 0 == cntr % k {
            borders = append(borders, nil)
    }

    // first prev will come from end of border list, 
    // then in loop it will be head of reversed chunk
    lastIdx := len(borders) -1
    prev := borders[lastIdx]
    idx := lastIdx -1

    for idx >= 0 {
        prev = reversePart(borders[idx], borders[idx + 1], prev)
        idx--
    }
    
    return prev
}