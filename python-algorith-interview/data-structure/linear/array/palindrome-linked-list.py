# 연결 리스트가 팰린드롬 구조인지 판별하라.
from typing import Collection, Deque
from typing import ListNode

def isPalindrome(self, head: ListNode) -> bool:
    # 데크 자료형 선언 (양방향 리스트)
    q: Deque = Collection.deque()

    if not head:
        return True
    
    node = head
    while node is not None:
        q.append(node.val)
        node = node.next
    
    while len(q) > 1:
        if q.popleft() != q.pop():
            return False
        
    return True

def isPalindromeByRunner(self, head: ListNode) -> bool:
    rev = None
    slow = fast = head
    # 런너를 이용해 역순 연결 리스트 구성
    while fast and fast.next:
        fast = fast.next.next
        rev, rev.next, slow = slow, rev, slow.next
    if fast:
        slow = slow.next
    
    while rev and rev.val == slow.val:
        slow, rev = slow.next, rev.next
    return not rev

# 무에서 유는 없다. 배워야 응용할 수 있다.