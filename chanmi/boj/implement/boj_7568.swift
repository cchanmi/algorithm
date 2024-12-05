//
//  boj_7568.swift
//  algorithm
//
//  Created by 황찬미 on 12/5/24.
//
//  덩치
//  https://www.acmicpc.net/problem/7568

let n = Int(readLine()!)!
var array = Array(repeating: Array(repeating: 0, count: 2), count: n)
var rankArray = Array(repeating: 1, count: n)

for i in 0..<n {
    array[i] = readLine()!.split(separator: " ").map{Int($0)!}
}

for i in 0..<n {
    for j in 0..<n {
        // 첫번째가 키도 크고, 몸무게도 많이 나갈 때
        if array[i][0] > array[j][0] && array[i][1] > array[j][1] {
            rankArray[j] += 1
        }
    }
}

for k in 0..<n {
    print(rankArray[k], terminator: " ")
}

