# 배열을 입력받아 합으로 0을 만들 수 있는 3가지 엘리먼트를 출력하라.
nums = [-1, 0, 1, 2, -1, -4]
# => [ [-1,0,1], [-1,-1,2] ]
nums2 = [-3,-2,0,1,1,1,2,3]

from typing import List


def threeSum(self, nums: List[int]) -> List[List[int]]:
    result = []
    nums.sort()

    for i in range(len(nums) - 2):
        # 중복 된 값 뛰어넘기
        if i > 0 and nums[i] == nums[-1]:
            continue
        # 간격을 좁혀가며 합 sum 계산
        left, right = i + 1, len(nums) - 1
        while left < right:
            sum = nums[i] + nums[left] + nums[right]
            if sum < 0:
                left += 1
            elif sum > 0:
                right -= 1
            else:
                # sum = 0인 경우이므로 정답 및 스킵 처리
                result.append([nums[i],nums[left],nums[right]])

                while left < right and nums[left] == nums[left+1]:
                    left +=1
                while left < right and nums[right] == nums[right-1]:
                    right -=1
                left += 1
                right -= 1
    return  result

print(threeSum('',nums))

# 투포인터를 이용하여 left, right, sum 등을 정의를 세운 후 문제를 해결
