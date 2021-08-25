from typing import List

# 216ms
def reverseStringTwoPointer(self, s: List[str]) -> None:
    left, right = 0, len(s) - 1
    while left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1
# 208ms
def reverseStringPython(self, s: List[str]) -> None:
    s.reverse()