# Based on node's values
def basedOnNodeValue(self, head):
    # code here
    if not head or not head.next:
        return head
        
    curr = head
    evenStart = None
    evenEnd = None
    oddStart = None
    while curr:
        if curr.data % 2 == 0:
            if not evenStart:
                evenStart = curr
                evenEnd = curr
            else:
                evenEnd.next = curr
                evenEnd = evenEnd.next
        else:
            if not oddStart:
                oddStart = curr
                oddEnd = curr
            else:
                oddEnd.next = curr
                oddEnd = oddEnd.next
        curr = curr.next
        
    if not oddStart:
        evenEnd.next = None
        return evenEnd
    
    evenEnd.next = oddStart
    oddEnd.next = None
    return evenStart

def basedOnIndexPos(self, head):
    if not head:
        return head
    curr1 = head
    curr2 = head.next
    head2 = curr2
    while curr2 and curr2.next and curr1.next:
        curr1.next = curr1.next.next
        curr1 = curr1.next
        curr2.next = curr2.next.next
        curr2 = curr2.next
    curr1.next = head2
    if curr2:
        curr2.next = None
    return head