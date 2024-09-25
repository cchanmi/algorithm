# LeetCode
# 17. Letter Combinations of a Phone Number
# https://leetcode.com/problems/letter-combinations-of-a-phone-number/

def letterCombinations(self, digits: str) -> [str]:
    dic = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz",
    }

    result = []

    def dfs(depth: int, now: str):
        if depth > len(array):
            return
        elif depth == len(array):
            result.append(now)
        else:
            for char in array[depth]:
                dfs(depth+1, now+char)

    array = []

    for digit in digits:
        array.append(dic[digit])

    if len(array) == 0:
        return []
    else:
        for char in array[0]:
            dfs(1, str(char))
    
    return result