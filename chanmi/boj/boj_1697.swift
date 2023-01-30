//
//  boj_1697.swift
//  algorithm
//
//  Created by 황찬미 on 2023/01/30.
//
//  숨바꼭질
//  https://www.acmicpc.net/problem/1697

import Foundation

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let K = input[1]
var count = 0
var result = 0

var queue = [(N, 0)]

// 0부터 100,000까지의 값이 있어야 해서 100001만큼의 배열의 크기를 만들어 주어야 함
var visited = Array(repeating: false, count: 100001)

// BFS

func bfs(_ x: Int) {
    while !queue.isEmpty {
        let (x, count) = queue.removeFirst()
        visited[x] = true
        
        if x == K {
            result = count
            break
        }
        
        if 0...100000 ~= x-1 && !visited[x-1] {
            queue.append((x-1, count+1))
            visited[x-1] = true
        }
        
        if 0...100000 ~= x+1 && !visited[x+1] {
            queue.append((x+1, count+1))
            visited[x+1] = true
        }
        
        if 0...100000 ~= x*2 && !visited[x*2] {
            queue.append((x*2, count+1))
            visited[x*2] = true
        }
    }
}

bfs(N)
print(result)

// 메모리 : 80412 KB, 시간 : 928 ms
