from typing import List
import sys

# 한번의 거래로 낼 수 있는 최대 이익을 산출하라.
input = [7,1,5,3,6,4]
# 1에서 사서 6에 팔면
reusult = 5

def maxProfit(self, prices: List[int]) -> int:
    minPrice = 0
    profit = sys.maxsize

# 이전 인덱스의 최솟값을 저장하면서 현재 인덱스와 비교 후 최솟값을 갱신한다.
# 포인터는 우측으로 이동하며 최솟값을 이용해 최대 이익을 갱신한다.
# 카데인 알고리즘?