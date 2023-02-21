//
//  boj_16395.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/20.
//
//  파스칼의 삼각형
//  https://www.acmicpc.net/problem/16395

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let n = input[0]
let k = input[1]
var dp = [[Int]]()

// 1부터 31까지 -> 31개인데 index가 0부터 시작하기 때문에 30개
for i in 1...31 {
    var row = [Int]()
    // i 개수에 맞는 개수의 값들을 넣어 줌
    for _ in 0..<i {
        row.append(1)
    }
    dp.append(row)
}

// 2부터 30까지 -> 첫번째 배열은 하나라서 확인할 필요 없음
for i in 2...30 {
    for j in 1..<i {
        dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
    }
}

print(dp[n-1][k-1])

// 메모리 : 69104 KB, 시간 : 8 ms
