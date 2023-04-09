//
//  boj_13303.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/09.
//
//  주유소
//  https://www.acmicpc.net/problem/13305

let input = Int(readLine()!)!
let distance = readLine()!.split(separator: " ").map{Int(String($0))!}
let cost = readLine()!.split(separator: " ").map{Int(String($0))!}
var minCost = cost[0]
var sum = 0

for i in 0..<distance.count {
    if minCost > cost[i] {
        minCost = cost[i]
    }
    sum += distance[i] * minCost
}

print(sum)

// 메모리 : 79612 KB, 시간 : 116 ms
