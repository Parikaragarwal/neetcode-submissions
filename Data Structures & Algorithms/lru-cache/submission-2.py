class Node:

    def __init__(self,key:int,val:int):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.map = {}
        self.dummy = Node(0,0)
        self.end = self.dummy
        self.count = 0
        self.cap = capacity
    
    def used(self,key: int):
        endprev = self.end
        curr = self.map[key]
        prev = curr.prev
        nxt = curr.next
        prev.next = nxt
        nxt.prev = prev
        endprev.next = curr
        curr.prev = endprev
        curr.next = None

        self.end = curr

        
    def get(self, key: int) -> int:
        if key not in self.map:
            return -1
        if self.map[key].next:
           self.used(key)
        return self.map[key].val

    def put(self, key: int, value: int) -> None:
        if key in self.map:
            self.map[key].val = value
            if self.map[key].next:
                self.used(key)
            return

        curr = Node(key,value)
        self.map[key] = curr
        curr.prev = self.end
        self.end.next = curr
        self.end = curr
        self.count+=1

        if self.count>self.cap:
           h:Node = self.dummy.next
           nh:Node = self.dummy.next.next
           nh.prev = self.dummy
           self.dummy.next = nh
           h.next = None
           h.prev = None
           self.map.pop(h.key,None)
           self.count-=1
        
        
        
