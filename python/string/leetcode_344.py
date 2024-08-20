# LeetCode
# 344. Reverse String
# https://leetcode.com/problems/reverse-string/
# s = [str]

def mySolution(s) -> None:
    # 그냥 뒤집는 방법
    s.reverse()
    
    # 공간복잡도가 O(1)이기 때문에 해당 상황을 고려한 방벙
    s[:] = s[::-1]
        
def twoPointersSolution(s) -> None:
    # 투 포인터 사용
    left = 0
    right = len(s)-1

    while left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1
