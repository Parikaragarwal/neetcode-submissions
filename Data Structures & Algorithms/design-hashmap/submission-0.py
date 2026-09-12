class Node:
    def __init__(self,key:int,val:int):
        self.key = key
        self.val = val
        self.next = None
class MyHashMap:

    def __init__(self):
        self.map = [Node(0,0) for _ in range(10**4)]
        self.mod = 10**4
        

    def put(self, key: int, value: int) -> None:
        curr:Node = self.map[key%self.mod]
        while curr.next:
            if curr.next.key == key:
                curr.next.val = value
                return
            curr = curr.next
        curr.next = Node(key,value)

    def get(self, key: int) -> int:
        curr:Node = self.map[key%self.mod]
        while curr.next:
            if curr.next.key == key:
                return curr.next.val
            curr = curr.next
        return -1
        

    def remove(self, key: int) -> None:
        curr:Node = self.map[key%self.mod]
        while curr.next:
            if curr.next.key == key:
                curr.next = curr.next.next
                return
            curr = curr.next
        return
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)