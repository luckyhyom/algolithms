
from typing import List

# 높이를 입력받아 비 온 후 얼마나 많은 물이 쌓일 수 있는지 계산하라.
inputValue = [0,1,0,2,1,0,1,3,2,1,2,1]
# inputValue = [1,2,1,2,3,1,0,2]

# => 6

def trap(self, height: List[int]) -> int:
    if not height:
        return 0
    
    volume = 0
    # 인덱스
    left, right = 0, len(height) - 1
    # 최대 길이 = 현재 위치 길이
    left_max, right_max = height[left], height[right]

    while left < right:
        # 현재 위치 길이 vs 최대 길이
        left_max, right_max = max(height[left], left_max), max(height[right], right_max)
        # 더 높은 쪽을 향해 투 포인터 이동
        if left_max <= right_max:
            volume += left_max - height[left]
            left += 1
        else:
            volume += right_max - height[right]
            right -= 1
    print(left_max,right_max)
    return volume

def trap2(self, height: List[int]) -> int:
    stack = []
    volume = 0
    for i in range(len(height)):
        print(inputValue)
        print(i,'>>','stack',stack)
        print(i,'>>','현재위치의 높이:',height[i])

        # 변곡점을 만나는 경우 (현재 위치의 높이가 이전 위치의 높이보다 크면 이전 위치를 꺼내어 탑으로 둔다.)
        while stack and height[i] > height[stack[-1]]:
            print(i,'>>','현재위치의 높이:',height[i],'height[stack[-1]]:', height[stack[-1]])
            # 스택에서 꺼낸다.
            top = stack.pop()
            print(i,'>>','top:',top)
            print(i,'>>','length',len(stack))
            if not len(stack):
                break
        
            # 이전과의 차이만큼 물 높이 처리
            distance = i - stack[-1] - 1
            print(i,'>>','distance:',distance)
            # 지금 높이? 이전이전 높이? - 최고높이
            print(i,'>>','현재위치의 높이:',height[i],'height[stack[-1]]:', height[stack[-1]],'height[top]:', height[top])
            waters = min(height[i], height[stack[-1]]) - height[top]

            volume += distance * waters
        
        stack.append(i)
    return volume

print(trap2('',inputValue))