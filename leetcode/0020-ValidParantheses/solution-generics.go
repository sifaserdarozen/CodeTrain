// Compute complexity O(N)
// Space complexity O(N)

type Stack[T any] struct {
	items []T
}

func (self Stack[T]) Empty() bool {
	if 0 == len(self.items) {
		return true
	}
	return false
}

func (self *Stack[T]) Pop() {
	if self.Empty() {
		return
	}
	self.items = self.items[:len(self.items)-1]
}

func (self Stack[T]) Top() any {
	return self.items[len(self.items)-1]
}

func (self *Stack[T]) Push(val T) {
	self.items = append(self.items, val)
}

func isValid(s string) bool {
	hist := &Stack[rune]{}

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
