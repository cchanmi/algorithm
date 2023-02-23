//
//  boj_9095.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/23.
//
//  1, 2, 3 더하기
//  https://www.acmicpc.net/problem/9095

let testCase = Int(readLine()!)!
var result = [Int]()

for _ in 0..<testCase {
    let number = Int(readLine()!)!
    var dp = [0, 1, 2, 4]
    
    if number >= 4 {
        for i in 4...number {
            dp.append(dp[i-1] + dp[i-2] + dp[i-3])
        }
    }
    print(dp[number])
}

// 메모리 : 69100 KB, 시간 : 8 ms
