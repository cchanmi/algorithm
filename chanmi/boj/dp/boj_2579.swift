//
//  boj_2579.swift
//  algorithm
//
//  Created by 황찬미 on 12/9/24.
//
//  계단 오르기
//  https://www.acmicpc.net/problem/2579

let n = Int(readLine()!)!
var dp = Array(repeating: 0, count: n+1)

var array: [Int] = [0]

for _ in 1...n {
    array.append(Int(readLine()!)!)
}

if n == 1 {
    print(array[1])
} else if n == 2 {
    print(array[1]+array[2])
} else if n == 3 {
    let result = max(array[1]+array[3], array[2]+array[3])
    print(result)
}else {
    dp[1] = array[1]
    dp[2] = array[1] + array[2]
    dp[3] = max(array[1]+array[3], array[2]+array[3])
    
    for i in 4...n {
        dp[i] = max(array[i]+dp[i-2], array[i]+array[i-1]+dp[i-3])
    }
    
    print(dp[n])
}
