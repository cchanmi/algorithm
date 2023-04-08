//
//  boj_11722.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/25.
//
//  가장 긴 감소하는 부분 수열
//  https://www.acmicpc.net/problem/11722

let input = Int(readLine()!)!
var array = readLine()!.split(separator: " ").map{Int(String($0))!}
var dp = Array(repeating: 1, count: input)

for i in 1..<input {
    for j in 0..<i {
        if array[i] < array[j] {
            dp[i] = max(dp[i], dp[j]+1)
        }
    }
}

print(dp.max()!)
