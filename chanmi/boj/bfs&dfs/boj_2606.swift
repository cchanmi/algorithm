//
//  boj_2606.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/01.
//
//  바이러스
//  https://www.acmicpc.net/problem/2606

import Foundation

let computerCount = Int(readLine()!)!
let linkedComputer = Int(readLine()!)!
var graph = Array(repeating: Array(repeating: 0, count: 0), count: computerCount+1)
var visited = Array(repeating: false, count: 101)
var count = 0

for _ in 0..<linkedComputer {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    let start = input[0]
    let end = input[1]
    graph[start].append(end)
    graph[end].append(start)
}

func bfs(_ x: Int) {
    visited[x] = true
    
    for i in graph[x] {
        if !visited[i] {
            bfs(i)
            count += 1
        }
    }
}

bfs(1)
print(count)

// 메모리 : 79516 KB, 시간: 12 ms
