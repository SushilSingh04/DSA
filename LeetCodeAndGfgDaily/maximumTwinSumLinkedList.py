from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def pairSumUsingStack(self, head: Optional[ListNode]) -> int:
        # Using stack
        if not head.next.next:
            return head.val + head.next.val

        stk = []
        slow = head
        fast = head

        while fast:
            stk.append(slow.val)
            slow = slow.next 
            fast = fast.next.next

        curr = slow
        maxSum = float('-inf')

        while curr:
            p = stk.pop()
            maxSum = max(maxSum, curr.val + p)
            curr = curr.next
        
        return maxSum
    
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow = head
        fast = head.next

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        curr = slow.next
        slow.next = None
        prev = None

        # None <- 2 <- 1 <- 3 <- 5 <- 4
        #                             p    c    s
        while curr:
            succ = curr.next
            curr.next = prev

            prev = curr
            curr = succ

        secondHead = prev
        maxSum = float('-inf')

        curr1 = head
        curr2 = secondHead

        while curr1:
            maxSum = max(maxSum, curr1.val + curr2.val)
            curr1 = curr1.next
            curr2 = curr2.next
        
        return maxSum