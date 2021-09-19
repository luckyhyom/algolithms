# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

# 정렬되어 있는 두 연결 리스트를 합쳐라.
# 1->2->4, 1->3->4
# => 1->1->2->3->4->4

class Test:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if (not l1) or (l2 and l1.val > l2.val):
            l1, l2 = l2, l1
        if l1:
            l1.next = self.mergeTwoLists(l1.next, l2)
        if l1 != None:
            print(l1.val)
        return l1

l1 = ListNode(1)
l1.next = ListNode(2)
l1.next.next = ListNode(4)
l2 = ListNode(1)
l2.next = ListNode(3)
l2.next.next = ListNode(4)

me = Test()
me.mergeTwoLists(l1,l2)