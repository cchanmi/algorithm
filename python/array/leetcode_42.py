# LeetCode
# 42. Trapping Rain Water
# https://leetcode.com/problems/trapping-rain-water/description/

def trap(height) -> int:
    # # 투 포인터로 접근

    if not height:
        return 0
    
    # 가장 큰 막대를 기준으로 left, right를 움직임.
    # 근데 이제 left보다 right가 더 크면 left를 이동시킴

    left, right = 0, len(height)-1
    left_max, right_max = 0, 0
    result = 0

    while left <= right:
        left_max, right_max = max(left_max, height[left]), max(right_max, height[right])

        if left_max < right_max:
            result += left_max - height[left]
            left += 1
        else:
            result += right_max - height[right]
            right -= 1
    
    return result