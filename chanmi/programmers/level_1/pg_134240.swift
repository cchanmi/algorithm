//
//  pg_134240.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/13.
//
//  푸드 파이트 대회
//  https://school.programmers.co.kr/learn/courses/30/lessons/134240

import Foundation

func solution(_ food:[Int]) -> String {
    var left = ""
    
    for i in 1..<food.count {
        let foodCount = food[i]/2
        if foodCount != 0 {
            for _ in 0..<foodCount {
                left += String(i)
            }
        }
    }

    let right = String(left.reversed())
    left += "0"
    
    let result = left + right
    return result
}

print(solution([1, 7, 1, 2]))
