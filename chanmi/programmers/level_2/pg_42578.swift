//
//  pg_42578.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/29.
//
//  위장
//  https://school.programmers.co.kr/learn/courses/30/lessons/42578#

func solution(_ clothes:[[String]]) -> Int {
    var dic = [String:Int]()
    var result = 1
    
    for oneClothes in clothes {
        let kind = oneClothes[1]
        
        dic[kind, default: 0] += 1
    }
    
    for value in dic.values {
        result *= (value+1)
    }
    
    return result-1
}

print(solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]))
