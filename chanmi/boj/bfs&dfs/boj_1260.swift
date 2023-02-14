//
//  boj_1260.swift
//  algorithm
//
//  Created by 황찬미 on 2023/01/25.
//
//  DFS와 BFS
//  https://www.acmicpc.net/problem/1260

import Foundation

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let M = input[1]
let V = input[2]

var graph = Array(repeating: Array(repeating: 0, count: 0), count: N+1)
var visited = Array(repeating: false, count: N+1)

// bfs 탐색을 위한 queue
var queue = [Int]()

for _ in 0..<M {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    let a = input[0]
    let b = input[1]
    graph[a].append(b)
    graph[b].append(a)
    graph[a].sort()
    graph[b].sort()
}

// dfs
func dfs(_ x: Int) {
    visited[x] = true
    print(x, terminator: " ")
    
    for i in graph[x] {
        if !visited[i] {
            dfs(i)
        }
    }
}

// bfs
func bfs(_ x: Int) {
    visited[x] = true
    queue.append(x)
    
    while !queue.isEmpty {
        let y = queue.removeFirst()
        print(y, terminator: " ")
        
        for i in graph[y] {
            if !visited[i] {
                queue.append(i)
                visited[i] = true
            }
        }
    }
}

dfs(V)
print("")
visited = Array(repeating: false, count: N+1)
bfs(V)

// 메모리 : 79784 KB, 시간: 32 ms
