//
//  pg_12949.swift
//  algorithm
//
//  Created by 황찬미 on 2023/05/07.
//
//  행렬의 곱셈
//  https://school.programmers.co.kr/learn/courses/30/lessons/12949

import Foundation

func solution(_ arr1:[[Int]], _ arr2:[[Int]]) -> [[Int]] {
    var result = Array(repeating: Array(repeating: 0, count: 0), count: arr1.count)
    
    for i in 0..<arr1.count {
        for j in 0..<arr2.count {
            var sum = 0
            for k in 0..<arr2[0].count {
                sum += arr1[i][k]*arr2[k][j]
            }
            result[i].append(sum)
        }
    }
    return result
}

_ = solution([[1, 4], [3, 2], [4, 1]], [[3, 3], [3, 3]])
