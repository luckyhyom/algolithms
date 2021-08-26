# 가장 긴 팰린드롬 부분 문자열을 출력하라.
palinderome = 'abacc'
# => 'aba'

def longestPalinderome(self, s: str) -> str:
    # 팰린드롬 판별 및 투 포인터 확장
    def expand(left: int, right: int) -> str:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left + 1:right]
    
    # 해당 사항이 없을 때 빠르게 리턴
    if len(s) < 2 or s == s[::-1]:
        return s

    result = ''
    #슬라이팅 윈도우 우측으로 이동
    for i in range(len(s) - 1):
        print(i)
        result = max(result,
                        expand(i, i + 1),
                        expand(i, i + 2),
                        key=len)
    return result

print(longestPalinderome('',palinderome))

# 팰린드롬은 가운데 문자열부터 모든 요소가 팰린드롬임
# 따라서 끝과 끝이 아닌 가운데 요소부터 검사하는 것이 맞음
# 홀수(3개)와 짝수(2개)의 윈도우가 우측으로 차례대로 검사함.

# ascii, unicode, utf-8(가변 길이 인코딩)
# 파이썬은 문자열 객체를 index로 조회하기 위해 utf-8 대신 각각 인코딩 방식을 정해놓음
# 01000000, 11000000, 11100000, 11110000