// Compute complexity O(N)
// Space complexity O(N)

type Stack struct {
	items []rune
}

func (self Stack) Empty() bool {
	if 0 == len(self.items) {
		return true
	}
	return false
}

func (self *Stack) Pop() {
	if self.Empty() {
		return
	}
	self.items = self.items[:len(self.items)-1]
}

func (self Stack) Top() rune {
	return self.items[len(self.items)-1]
}

func (self *Stack) Push(val rune) {
	self.items = append(self.items, val)
}

func isValid(s string) bool {
	hist := &Stack{}

	for _, r := range s {
		switch r {
		case '}':
			if hist.Empty() || '{' != hist.Top() {
				return false
			}
			hist.Pop()
		case ')':
			if hist.Empty() || '(' != hist.Top() {
				return false
			}
			hist.Pop()
		case ']':
			if hist.Empty() || '[' != hist.Top() {
				return false
			}
			hist.Pop()
		case '(', '{', '[':
			hist.Push(r)
		}
	}

	return hist.Empty()
}
