//
//  boj_10451.swift
//  algorithm
//
//  Created by 황찬미 on 2023/01/24.
//
//  순열 사이클
//  https://www.acmicpc.net/problem/10451

import Foundation

let T = Int(readLine()!)!

for _ in 0..<T {
    let N = Int(readLine()!)!
    var permutation = readLine()!.split(separator: " ").map{Int(String($0))!}
    permutation.insert(0, at: 0)
    var visited = Array(repeating: false, count: N+1)
    
    func dfs(_ start: Int) {
        visited[start] = true
        let next = permutation[start]
        
        if !visited[next] {
            dfs(next)
        }
    }
    
    var cycle = 0
    for i in 1...N {
        if !visited[i] {
            dfs(i)
            cycle += 1
        }
    }
    
    print(cycle)
}

// 메모리 : 79516 KB, 시간 : 164 ms
