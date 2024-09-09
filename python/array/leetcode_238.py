# LeetCode
# 238. 자신을 제외한 배열의 곱
# https://leetcode.com/problems/product-of-array-except-self/

def productExceptSelf(self, nums: List[int]) -> List[int]:
    # 시간 복잡도 초과
    result = []

    for i in range(len(nums)):
        sum = 1
        for j in range(len(nums)):
            # 자신을 제외한다
            if i == j:
                continue
            else:
                 sum *= nums[j]
            
        result.append(sum)
        
    # O(n)으로 접근해야 하는 풀이
    out = []
    p = 1

    for i in range(0, len(nums)):
        out.append(p)
        p = p * nums[i]
  
    p = 1

    for i in range(len(nums) - 1, -1, -1):
        out[i] = out[i] * p
        p = p * nums[i]
        
    return out