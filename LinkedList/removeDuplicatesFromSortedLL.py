def removeDuplicates(head):
    #code here
    curr1 = head
    curr2 = head
    while curr2:
        while curr2 and curr1.data == curr2.data:
            curr2 = curr2.next
        curr1.next = curr2
        curr1 = curr2
    return head