# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


# def mergeTwoLists(self, list1, list2):
#     merged = ListNode()
#     head = merged
#     curr1 = list1
#     curr2 = list2
#     while curr1 and curr2:
#         if curr1.val > curr2.val:
#             merged.next = curr2
#             curr2 = curr2.next
#         else:
#             merged.next = curr1
#             curr1 = curr1.next
#         merged = merged.next

#     while curr1:
#         merged.next = curr1
#         merged = merged.next
#         curr1 = curr1.next
#     while curr2:
#         merged.next = curr2
#         merged = merged.next
#         curr2 = curr2.next
#     return head.next
from queue import PriorityQueue
pq = PriorityQueue()
pq.put((1,2))
pq.put((3,4))
pq.put((7,2))
print(pq.get()[1])
while not pq.empty():
    print(pq.get())