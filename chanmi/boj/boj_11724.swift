//
//  boj_11724.swift
//  algorithm
//
//  Created by 황찬미 on 2023/01/30.
//
//  연결 요소의 개수
//  https://www.acmicpc.net/problem/11724

import Foundation

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let M = input[1]
var graph = Array(repeating: Array(repeating: 0, count: 0), count: N+1)
var visited = Array(repeating: false, count: N+1)
var count = 0

for _ in 0..<M {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    let u = input[0]
    let v = input[1]
    graph[u].append(v)
    graph[v].append(u)
}

func dfs(_ x: Int) {
    visited[x] = true
    
    for i in graph[x] {
        if !visited[i] {
            dfs(i)
        }
    }
}

for i in 1...N {
    if !visited[i] {
        dfs(i)
        count += 1
    }
}

print(count)

// 메모리 : 88216 KB, 시간 : 636 ms
