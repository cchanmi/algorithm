# LeetCode
# 125. Valid Palindrome
# https://leetcode.com/problems/valid-palindrome/

class Solution:
    def isPalindrome(self, s: str) -> bool:

        # 나라면 대문자를 모두 소문자로 바꾼 다음에, 문자가 아닌 것들을 전부 제거할 것 같습니다.
        # 1. 문자만 놔둠
        # 2. 소문자로 다 바꿈
        # 3. 뒤집었을 때 같은지 확인

        temp = ""
        # 알파벳이라면

        for i in s:
            if i.isalnum():
                temp += i.lower()
        
        if temp == temp[::-1]:
            return True
        else:
            return False