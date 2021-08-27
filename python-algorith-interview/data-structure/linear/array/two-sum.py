from typing import List

# 덧셈하여 타겟을 만들 수 있는 두 숫자 인덱스를 리턴하라.
nums = [2, 7, 11, 15]
target = 9
# => [0, 1]

# O(n^2), 5,284ms
def twoSum(self, nums: List[int], target: int) -> List[int]:
    for i in range(len(nums)):
        print(i)
        for j in range(i + 1, len(nums)):
            if nums[i] + nums[j] == target:
                return [i, j]

# O(n), 864ms
def twoSumByIn(self, nums: List[int], target: int) -> List[int]:
    for i, n in enumerate(nums):
        # target = n + complement
        complement = target - n
        # 7 = 9 - 2 , i = 0
        # 1~len ?
        # 7
        if complement in nums[i + 1:]:
            return [nums.index(n), nums[i + 1:].index(complement) + (i + 1)]

# O(1)~O(n), 48ms
def twoSumByDict(self, nums: List[int], target: int) -> List[int]:
    nums_map = {}
    # 키와 값을 바꿔서 딕셔너리로 저장
    for i, num in enumerate(nums):
        nums_map[num] = i
    # 타겟에서 첫번째 수를 뺀 결과를 키로 조회
    for i, num in enumerate(nums):
        # i != nums_map[target - num] 이게 false일 수 있나?
        if target - num in nums_map and i != nums_map[target - num]:
            return [i, nums_map[target - num]]

# one loop & dictionary
def twoSumByOneLoopAndDict(self, nums: List[int], target: int) -> List[int]:
    nums_map = {}
    for i, num in enumerate(nums):
        if target - num in nums_map:
            return [nums_map[target - num], i]
        nums_map[num] = i



print(twoSumByOneLoopAndDict('',[2,4,11,4,4,4,9,15,7],target))



# enumerate(nums): return [index, value]
# 보수 구하기 C-A=B -> A+B=C
# for KEY in MAP

# 인덱스를 구하는 문제일 경우 인덱스를 섞지 않도록 주의.