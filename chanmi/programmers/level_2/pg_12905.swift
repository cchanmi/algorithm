//
//  pg_12905.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/26.
//
//  가장 큰 정사각형 찾기
//  https://school.programmers.co.kr/learn/courses/30/lessons/12905

import Foundation

func solution(_ board:[[Int]]) -> Int {
    let row = board[0].count
    let col = board.count
    var dp = Array(repeating: Array(repeating: 0, count: row+1), count: col+1)
    var result = 0
    
    for i in 0..<col {
        for j in 0..<row {
            dp[i+1][j+1] = board[i][j]
        }
    }

    
    for i in 1...col {
        for j in 1...row {
            if dp[i][j] != 0 {
                dp[i][j] = min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])+1
                result = max(result, dp[i][j])
            }
        }
    }

    return result*result
}

_ = solution([[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]])
