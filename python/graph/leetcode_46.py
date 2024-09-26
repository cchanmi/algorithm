# LeetCode
# 46. Permutations
# https://leetcode.com/problems/permutations/

from itertools import permutations

def permute(nums):

        result = []
        # visited = [False * len(nums)] 처음에 이렇게 했다가 [0] 돼서 에러남
        visited = [False] * len(nums)

        def dfs(depth, now):
            if depth == len(nums):
                result.append(now)
                return
            else:
                for i in range(len(nums)):
                    if not visited[i]:
                        visited[i] = True
                        dfs(depth+1, now+[nums[i]])
                        visited[i] = False
        
        dfs(0, [])
        
        return result
    

def permuteLibrary(nums):

       result = []

       for permu in permutations(nums, len(nums)):
           result.append(list(permu))
       
       return result