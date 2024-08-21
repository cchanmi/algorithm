# LeetCode
# 819. Most Common Word
# https://leetcode.com/problems/most-common-word/description/

import re

def mySolution(paragraph, banned) -> str:
    
    # 금지된 단어 제외, 가장 많이 등장하는 단어 출력
    # 대소문자 구분 x, 구두점 또한 무시

    # 먼저 소문자로 만들고, 공백이랑 쉼표 기준으로 다름
    
    dic = {}

    tempArray = re.sub(r'[,.]', '', paragraph)
    splitArray = tempArray.split()

    for string in splitArray:
        lowerString = string.lower()

        if lowerString not in dic:
            dic[lowerString] = 1
        else:
            dic[lowerString] += 1
    
    for ban in banned:
        del dic[ban]


    return max(dic, key=dic.get)

import collections

def otherSolution(paragraph, banned) -> str:

    words = [word for word in re.sub(r'[^\w]', ' ', paragraph)
                 .lower().split()
                    if word not in banned]
    
    # defaultdic을 통해 키 존재 유무 확인할 필요 없이 값 처리하는 방법
    # counts = collections.defaultdict(int)
    # for word in word: counts[word] += 1
    
    # Counter 클래스를 통해 dic의 단어 개수 체크
    dic = collections.Counter(words)
    return dic.most_common(1)[0][0]

print(mySolution("Bob hit a ball, the hit BALL flew far after it was hit.", ["hit"]))