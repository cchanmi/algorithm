# LeetCode
# 561. 배열 파티션
# https://leetcode.com/problems/array-partition/description/

from itertools import combinations

def arrayPairSum(nums) -> int:
    # 정렬하여서 작은 순서대로 Min 메서드 사용

    result = 0
    nums.sort()

    # min 메서드 사용
    for i in range(0, len(nums), 2):
        result += min(nums[i], nums[i+1])
    
    # 짝수값만 계산하는 방법
    for i in range(0, len(nums), 2):
        result += nums[i]
    
    # [::2]는 두칸씩 컨너뛰므로 짝수 번째를 계산함
    result = sum(sorted(nums)[::2])

    return result