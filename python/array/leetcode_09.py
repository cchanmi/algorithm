# LeetCode
# 09. 세 수의 합
# https://leetcode.com/problems/3sum/

def threeSum(self, nums: List[int]) -> List[List[int]]:

    # 투 포인터로 접근하는 방법

    result = []
    nums.sort()

    for i in range(len(nums)-2):
        
        # 이전의 값과 같다면 똑같을 수 있게 때문에 해당 코드 추가
        if i > 0 and nums[i] == nums[i-1]:
            continue

        left, right = i+1, len(nums)-1

        while left < right:
            sum = nums[i] + nums[left] + nums[right]

            if sum < 0:
                left += 1
            elif sum > 0:
                right -= 1
            else:
                # 0이 된 상황
                result.append([nums[i], nums[left], nums[right]])

                # left, right의 중복을 체크하는 것.
                while left < right and nums[left] == nums[left + 1]:
                    left += 1
                while left < right and nums[right] == nums[right - 1]:
                    right -= 1
                
            # 전부 다 빠져 나왔다면 while문을 나와야 하기 때문에 값을 더해 주고 빼줌
                left += 1
                right -= 1
    
    return result