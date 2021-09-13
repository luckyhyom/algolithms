# 이해 필요
from typing import List

# 배열을 입력받아 output[i]가 자신을 제외한 나머지 모든 요소의 곱셈 결과가 되도록 출력하라.
# 입력
input = [1,2,3,4]
# => 출력

def productExceptSelf(self, nums: List[int]) -> List[int]:
    out = []
    p = 1
    # 왼쪽 곱셈
    for i in range(0,len(nums)):
        out.append(p)
        p = p * nums[i]
    p = 1
    # 왼쪽 곱셈 결과에 오른쪽 값을 차례대로 곱셈
    for i in range(len(nums) - 1, 0 - 1, - 1):
        out[i] = out[i] * p
        p = p * nums[i]
    return out

print('pro',productExceptSelf('',input))