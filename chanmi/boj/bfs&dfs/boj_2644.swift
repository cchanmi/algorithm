//
//  boj_2644.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/06.
//
//  촌수계산
//  https://www.acmicpc.net/problem/2644

import Foundation

let N = Int(readLine()!)!
let totalPerson = readLine()!.split(separator: " ").map{Int(String($0))!}
let fisrtPerson = totalPerson[0]
let secondPerson = totalPerson[1]
let edge = Int(readLine()!)!
var graph = Array(repeating: Array(repeating: 0, count: 0), count: N+1)
var visited = Array(repeating: false, count: N+1)
var queue: (Int)
var result = -1

for _ in 0..<edge {
    let node = readLine()!.split(separator: " ").map{Int(String($0))!}
    let a = node[0]
    let b = node[1]
    graph[a].append(b)
    graph[b].append(a)
}

func bfs(_ start: Int, _ count: Int) {
    // 문제에서 요구한 사람의 노드에 도착했을 경우,
    if start == secondPerson {
        result = count
        return
    }
    
    visited[start] = true
    
    for i in graph[start] {
        if !visited[i] {
            visited[i] = true
            bfs(i, count+1)
        }
    }
}

bfs(fisrtPerson, 0)
print(result)

// 메모리 : 69108 KB, 시간 : 8 ms
