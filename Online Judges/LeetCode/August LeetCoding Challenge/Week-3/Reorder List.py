# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
#         if head == None or head.next == None:
#             return
#         firstHalf = head
#         secondHalf = head.next
#         while firstHalf.next != None and secondHalf.next.next != None:
#             firstHalf = firstHalf.next
#             secondHalf = secondHalf.next.next

#         middle = firstHalf
#         secondRev = firstHalf.next

#         while secondRev.next != None:
#             cur = secondRev.next
#             secondRev.next = cur.next
#             cur.next = middle.next
#             middle.next = cur

#         firstHalf = head
#         secondHalf = middle.next
#         while firstHalf != middle:
#             middle.next = secondHalf.next
#             secondHalf.next = firstHalf.next
#             firstHalf.next = secondHalf
#             firstHalf = secondHalf.next
#             secondHalf = middle.next
        if not head or not head.next:
            return
        fast = head
        slow = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        middle = slow.next
        slow.next = None

        last = None
        currentNode = middle

        while currentNode:
            nextNode = currentNode.next
            currentNode.next = last
            last = currentNode
            currentNode = nextNode

        tail = head
        remain = head
        remain = remain.next
        while last:
            tail.next = last
            tail = tail.next
            last = last.next
            if remain:
                remain, last = last, remain
