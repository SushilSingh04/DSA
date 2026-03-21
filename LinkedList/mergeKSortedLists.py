from typing import Optional, List
from queue import PriorityQueue

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    
def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        dNode = ListNode()
        tmp = dNode
        pq = PriorityQueue()
        counter = 0
        for head in lists:
            if head:
                pq.put((head.val, counter, head))
                counter += 1
        while not pq.empty():
            curr = pq.get()[2]
            tmp.next = curr
            tmp = tmp.next
            if curr.next:
                pq.put((curr.next.val, counter, curr.next))
                counter += 1
        return dNode.next