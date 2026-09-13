class Node:
    def __init__(self, key: int, val: int, feq: int):
        self.key = key
        self.val = val
        self.feq = feq
        self.prev = None
        self.next = None


class List:
    def __init__(self, feq: int):
        self.dummy = Node(0, 0, feq)
        self.end = self.dummy

    def isEmpty(self) -> bool:
        return not self.dummy.next

    def insertEnd(self,el: Node):
        self.end.next = el
        el.prev = self.end
        self.end = el
        return

    def delete(self,el: Node):
        if el == self.end:
            self.end = el.prev
            self.end.next = None
            el.prev = None
            return
        p: Node = el.prev
        n: Node = el.next

        p.next = n
        n.prev = p
        el.next = None
        el.prev = None
        return

    def delfirst(self)->Node:
        n: Node = self.dummy.next
        if n == self.end:
            self.dummy.next = None
            self.end = self.dummy
            n.prev = None
            return n
        nh: Node = n.next
        self.dummy.next = nh
        nh.prev = self.dummy
        n.next = None
        n.prev = None
        return n


class LFUCache:
    def __init__(self, capacity: int):
        self.map = {}
        self.feqmap = {}
        self.minfeq: int = 1
        self.count = 0
        self.cap = capacity

    def updateNode(self, curr):
        cf = curr.feq

        self.feqmap[cf].delete(curr)

        if self.feqmap[cf].isEmpty():
            self.feqmap.pop(cf, None)
            if cf == self.minfeq:
                self.minfeq += 1

        curr.feq += 1
        if curr.feq not in self.feqmap:
            self.feqmap[curr.feq] = List(curr.feq)
        self.feqmap[curr.feq].insertEnd(curr)

    def get(self, key: int) -> int:
        if key not in self.map:
            return -1
        curr = self.map[key]
        self.updateNode(curr)
        return curr.val

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            curr: Node = self.map[key]
            curr.val = value
            self.updateNode(curr)
            return

        self.count += 1
        curr: Node = Node(key, value, 1)
        self.map[key] = curr
        if 1 not in self.feqmap:
            self.feqmap[1] = List(1)
        self.feqmap[1].insertEnd(curr)

        if self.count > self.cap:
            delnode:Node = self.feqmap[self.minfeq].delfirst()
            if self.feqmap[self.minfeq].isEmpty():
                del self.feqmap[self.minfeq]
            self.count -= 1
            del self.map[delnode.key]

        self.minfeq = 1


# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
