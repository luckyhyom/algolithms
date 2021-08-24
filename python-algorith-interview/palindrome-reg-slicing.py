import collections
import re
from typing import Deque

# 304ms
class ByList:
    def isPalindrome(self, s:str) -> bool:
        strs = []
        for char in s:
            print(char)
            if char.isalnum():
                strs.append(char.lower())

            # 팰린드롬 여부 판별
        while len(strs) > 1:
            if strs.pop(0) != strs.pop():
                return False
        return True

# 64ms
class ByDeque:
    def isPalindrome(self, s:str) -> bool:
        # 자료형 데크로 선언 (속도 5배 향상)
        strs: Deque = collections.deque()
        for char in s:
            print(char)
            if char.isalnum():
                strs.append(char.lower())

        while len(strs) > 1:
            if strs.popleft() != strs.pop():
                return False
        return True

# 36ms
class ByRegexes:
    def isPalindrome(self, s:str) -> bool:
        s = s.lower()
        # 정규식으로 반복문 없이 핕터링
        s = re.sub('[^a-z0-9]', '', s)

        return s == s[::-1] # 슬라이싱


# 자료구조를 이해하고 적절한 자료구조를 사용하여 알고리즘을 구현한다.
# pop을 사용하여 요소를 조회 및 추출한다.
# 정규표현식을 사용하여 반복문 사용을 피한다.
# C에서는 포인터를 직접 조작하여 속도를 높일 수 있다. (4ms)
# 문자열 조작은 슬라이싱을 활용한다. (슬라이싱 기능은 C로 구현되어있다.)

# 슬라이싱
strs = 'abcd'
deepCopy = strs[:]
reversed = strs[::-1]
oddStrs = strs[::2]
