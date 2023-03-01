package solution

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func mergeKLists(lists []*ListNode) *ListNode {
    var head *ListNode
    var tail *ListNode
    
    for {
        var smallest *ListNode
        var smallestIdx = 0
        for k, v := range(lists) {
            if v != nil && (nil == smallest || v.Val < smallest.Val) {
                smallestIdx = k
                smallest = v
            }
        }
        if nil == smallest {
            return head
        }

        lists[smallestIdx] = smallest.Next

        if nil != tail {
            tail.Next = &ListNode{Val : smallest.Val, Next: nil}
            tail = tail.Next
        } else {
            head = &ListNode{Val : smallest.Val, Next: nil}
            tail = head       
        }
    }
}