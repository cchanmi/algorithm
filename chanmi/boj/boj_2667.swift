//
//  boj_2667.swift
//  algorithm
//
//  Created by 황찬미 on 2023/01/26.
//
//  단지번호붙이기
//  https://www.acmicpc.net/problem/2667

import Foundation

let input = Int(readLine()!)!
var graph = [[Int]]()
var visited = Array(repeating: Array(repeating: false, count: input), count: input)
var houseArray = [Int]()
var count = 0

for _ in 0..<input {
    graph.append(readLine()!.map{Int(String($0))!})
}

let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

for i in 0..<input {
    for j in 0..<input {
        // 집이 있는 곳이며, 방문하지 않은 집일 경우
        if graph[i][j] == 1 && !visited[i][j] {
            count = 0
            dfs(i, j)
            houseArray.append(count)
        }
    }
}

func dfs(_ x: Int, _ y: Int) {
    visited[x][y] = true
    count += 1
    
    for i in 0..<4 {
        let nx = x + dx[i]
        let ny = y + dy[i]
        
        if 0..<input ~= nx && 0..<input ~= ny && !visited[nx][ny] && graph[nx][ny] == 1 {
            dfs(nx, ny)
        }
    }
}

print(houseArray.count)
houseArray.sort()
for i in 0..<houseArray.count {
    print(houseArray[i])
}

// 메모리 : 79516 KB, 시간 : 12 ms
