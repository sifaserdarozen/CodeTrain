package solution

type Node struct {
    key int
    value int
    prev *Node
    next *Node
}

type CacheQueue struct {
    head *Node
    tail *Node
    size int
}

func (self *CacheQueue)Push(key int, value int) *Node {
    node := &Node{key: key, value: value, prev: nil, next: self.head}
    if nil != node.next {
        node.next.prev = node
    }
    self.head = node
    if nil == self.tail {
        self.tail = self.head
    }
    self.size++
    return self.head
}

func (self *CacheQueue)Pop() int {
    key := self.tail.key
    if self.tail == self.head {
        self.tail = nil
        self.head = nil
        self.size = 0
    } else {
        self.tail = self.tail.prev
        self.tail.next.prev = nil
        self.tail.next = nil
        self.size--
    }

    return key
}

func (self *CacheQueue)Update(node *Node, value int) {
    node.value = value
    if self.head == node {
    } else if self.tail == node {
        newtail := self.tail.prev
        newtail.next = nil
        self.tail.prev = nil
        self.tail.next = self.head
        self.head.prev = self.tail
        self.head = self.tail
        self.tail = newtail
    } else {
        node.next.prev = node.prev
        node.prev.next = node.next
        node.next = self.head
        node.prev = nil
        self.head.prev = node
        self.head = node
    }
}


type LRUCache struct {
    queue CacheQueue
    dict map[int](*Node)
    capacity int
}


func Constructor(capacity int) LRUCache {
    return LRUCache{dict: make(map[int](*Node)), capacity: capacity}
}


func (this *LRUCache) Get(key int) int {
    if v, ok := this.dict[key]; ok {
        value := v.value
        this.queue.Update(v, value)
        return value
    } else {
        return -1
    }
}

func (this *LRUCache) Put(key int, value int)  {
    if v, ok := this.dict[key]; ok {
        this.queue.Update(v, value)
    } else {
        node := this.queue.Push(key, value)
        this.dict[key] = node

        // check if we need to remove oldest item
        for this.capacity < this.queue.size {
            key := this.queue.Pop()
            delete(this.dict, key)
        }
    }
}
