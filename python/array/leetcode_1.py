# LeetCode
# 1. Two Sum
# https://leetcode.com/problems/two-sum/description/

def twoSum(nums, target: int):
    # 1. 무식하게 전부 해 보는 방법 O(n^2)

    for i in range(0, len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i]+nums[j] == target:
                return [i, j]

    # 2. 첫 번째 수를 빼면 두 번째 값이 바로 나오기 때문에 dic로 조회 O(n)
    dic = {}

    for index, num in enumerate(nums):
        dic[num] = index
    
    for i, num in enumerate(nums):
        if (target - num) in dic and i != dic[target-num]:
            return [i, dic[target-num]]

    # 투 포인터 풀이 -> 정렬된 값으로 오지 않기 때문에 사용 불가능

twoSum([2,7,11,15], 9)