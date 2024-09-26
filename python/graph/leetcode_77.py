# LeetCode
# 77. Combinations
# https://leetcode.com/problems/combinations/

def combinationLibrary(n, k):

    number = []
    result = []

    for i in range(n):
        number.append(i+1)
    
    for combi in combinations(number, k):
        result.append(list(combi))
    
    return result

def combination(n, k):

    number = []
    result = []

    for i in range(n):
        number.append(i+1)
    
    def combination(depth: int, now: [int], index: int):
        if depth == k:
            result.append(now)
            return
        else:
            for i in range(index, n):
                combination(depth+1, now+[number[i]], i+1)
    
    combination(0, [], 0)

