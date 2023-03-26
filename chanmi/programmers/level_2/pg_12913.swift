//
//  pg_12913.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/27.
//
//  땅따먹기
//  https://school.programmers.co.kr/learn/courses/30/lessons/12913

import Foundation

func solution(_ land:[[Int]]) -> Int{
    let row = land[0].count
    let col = land.count
    var dp = Array(repeating: Array(repeating: 0, count: row), count: col+1)
    
    for i in 0..<col {
        for j in 0..<row {
            dp[i+1][j] = land[i][j]
        }
    }
    
    for i in 1...col {
        for j in 0..<row {
            let now = dp[i][j]
            for k in 0..<row {
                if j == k {
                    continue
                } else {
                    dp[i][j] = max(dp[i-1][k]+now, dp[i][j])
                }
            }
        }
    }
    
    return dp[col].max()!
}

print(solution([[1,2,3,5],[5,6,7,8],[4,3,2,1]]))
