# LeetCode
# 5. Longest Palindromic Substring
# https://leetcode.com/problems/longest-palindromic-substring/description/

def mySolution(s) -> str:

    array = []

    for i in range(1, len(s)+1):
        for j in range(len(s)-i+1):
            now = s[j:j+i]
            if now == now[::-1]:
                array.append(now)
    
    # 좀 더 객관적인 for문 방식...
    for start in range(len(s)):
        for end in range(start + 1, len(s) + 1):
            now = s[start:end]
            if now == now[::-1]:
                array.append(now)

    return max(array, key=len)

def otherSolution(s) -> str:
    # 팰린드롬은 홀수일 경우와 짝수일 경우를 고려해 주어야 함.

    if len(s) < 2 or s == s[::-1]:
        return s

    def expand(left: int, right: int) -> str:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return s[left+1:right]

    result = ''
    for i in range(len(s)):
        result = max(result, expand(i, i+1), expand(i, i+2), key=len)

    return result

mySolution("babad")