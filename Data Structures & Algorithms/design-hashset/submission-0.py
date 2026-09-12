class Node:
    def __init__(self,val):
        self.key = val
        self.next = None
class MyHashSet:

    def __init__(self):
        self.set = [Node(0) for i in range(0,10**4)]
        self.mod = len(self.set)

    def add(self, key: int) -> None:
        curr:Node = self.set[key%self.mod]
        while curr.next:
            if curr.next.key == key:
                return
            curr = curr.next
        
        curr.next = Node(key)

        

    def remove(self, key: int) -> None:
        curr = self.set[key%self.mod]

        while curr.next:
            if curr.next.key == key:
                curr.next = curr.next.next
                return
            curr = curr.next

        

    def contains(self, key: int) -> bool:
        curr = self.set[key%self.mod]
        while curr.next:
            if curr.next.key == key:
                return True
            curr = curr.next
        return False
        


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)