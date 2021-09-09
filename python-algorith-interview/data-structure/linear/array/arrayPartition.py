from typing import List

# n개의 페어를 이용한 min(a,b)의 합으로 만들 수 있는 가장 큰 합을 출력하라.
nums = [1,4,2,3]
# => min(1,2) + min(3,4) = 4

def pairSum(self, nums: List[int]):
    sum = 0
    pair = []
    nums.sort()
    for n in nums:
        pair.append(n)
        if len(pair) == 2:
            sum += min(pair)
            pair = []
    return sum

def pairSumEven(self, nums: List[int]):
    sum = 0
    nums.sort()
    for i, n in enumerate(nums):
        if i % 2 == 0:
            sum += n
    return sum

def pairSumPython(self, nums: List[int]):
    return sum(sorted(nums)[::2])

print(pairSum('',nums))
print(pairSumEven('',nums))
print(pairSumPython('',nums))



