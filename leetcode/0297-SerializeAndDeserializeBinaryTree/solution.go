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

 import "strconv"

 type Codec struct {
 }
 
 func Constructor() Codec {
	 return Codec{}
 }
 
 // Serializes a tree to a single string.
 func (this *Codec) serialize(root *TreeNode) string {
	 return serializeTree(root, "")
 }
 
 func serializeTree(node *TreeNode, serial string) string {
	 if nil == node{
		 serial += "nill "
		 return serial
	 }
 
	 serial += strconv.Itoa(node.Val)
	 serial += " "
	 serial = serializeTree(node.Left, serial)
	 serial = serializeTree(node.Right, serial)
 
	 return serial
 }
 
 // Deserializes your encoded data to tree.
 func (this *Codec) deserialize(data string) *TreeNode {
	 serial := strings.Split(data, " ")
	 root, _ := deserializeTree(serial, 0)
	 return root
 }
 
 func deserializeTree(serial []string, idx int) (*TreeNode, int) {
	 val, err := strconv.Atoi(serial[idx])
	 if nil != err {
		 return nil, idx + 1
	 }
 
	 left, idx := deserializeTree(serial, idx + 1)
	 right, idx := deserializeTree(serial, idx)
 
	 return &TreeNode{Val: val, Left: left, Right: right}, idx
 }
 
 
 /**
  * Your Codec object will be instantiated and called as such:
  * ser := Constructor();
  * deser := Constructor();
  * data := ser.serialize(root);
  * ans := deser.deserialize(data);
  */