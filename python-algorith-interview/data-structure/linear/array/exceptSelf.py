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

# [1,2,3,4]에서 자신을 제외한 왼쪽의 곱 x 오른쪽의 곱
# 1은 왼쪽에 아무것도 없으므로 왼쪽의 곱은 1
# 오른쪽에는 2,3,4가 있으므로 오른쪽의 곱은 24
# [1,1,2,6] * [1,4,12,24]
# 처음 배열은 nums의 첫번째 인덱스부터 담겨있고 다음 배열은 nums의 마지막 인덱스부터 담겨있다.
# 둘중 하나를 역순으로 하여 곱한다. (동일한 인덱스의 왼쪽,오른쪽 곱을 매칭시키기 위해)