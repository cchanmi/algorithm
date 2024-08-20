# LeetCode
# 125. Valid Palindrome
# https://leetcode.com/problems/valid-palindrome/

import collections
import re

# 알파벳, 숫자임을 판단하고, 소문자로 변환해 준 다음 팰린드롬인지를 확인하는 방식
def mySolution(s: str) -> bool:
    temp = ""

    for i in s:
        if i.isalnum():
            temp += i.lower()
        
    if temp == temp[::-1]:
        return True
    else:
        return False

# 배열을 이용하여서 첫 번째 값과 마지막 값을 비교하여 팰린드롬인지를 확인하는 방식 
def listSolution(s: str) -> bool:
    list = []

    for i in s:
        if i.isalnum():
            list.append(i.lower())
    
    while len(list) > 1:
        if list.pop(0) != list.pop():
            return False
        
    return True

# 배열을 이용한 것보다 시간복잡도를 좀 더 개선한 방법 deque 사용
def dequeSolution(s: str) -> bool:
    deque = deque()

    for i in s:
        if i.isalnum():
            deque.append(i.lower())
    
    while len(deque) > 1:
        if deque.popleft() != deque.pop():
            return False
        
        return True

# 정규식과 문자열 슬라이싱을 이용한 방법
def slicingSolution(s: str) -> bool:
    s = s.lower()
    s = re.sub('[^a-z0-9]', '', s)
    
    return s == s[::-1]    
    