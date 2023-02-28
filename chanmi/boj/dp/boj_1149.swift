//
//  boj_1149.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/28.
//
//  RGB거리
//  https://www.acmicpc.net/problem/1149

let N = Int(readLine()!)!
var RGBArray = Array(repeating: Array(repeating: 0, count: 3), count: 1)

for _ in 1...N {
    RGBArray.append(readLine()!.split(separator: " ").map{Int(String($0))!})
}

var dp = Array(repeating: Array(repeating: 0, count: 3), count: N+1)

for i in 1...N {
    dp[i][0] = RGBArray[i][0]+min(dp[i-1][2], dp[i-1][1])
    dp[i][1] = RGBArray[i][1]+min(dp[i-1][2], dp[i-1][0])
    dp[i][2] = RGBArray[i][2]+min(dp[i-1][1], dp[i-1][0])
}

print(dp[N].min()!)

// 메모리 : 69240 KB, 시간 : 8 ms
