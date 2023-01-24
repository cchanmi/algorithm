//
//  boj_2178.swift
//  algorithm
//
//  Created by 황찬미 on 2023/01/22.
//
//  미로 탐색
//  https://www.acmicpc.net/problem/2178

import Foundation

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let M = input[1]

var graph = [[Int]]()
var queue = [(0, 0)]

for _ in 0..<N {
    let number = readLine()!.map{Int(String($0))!}
    graph.append(number)
}

let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

while !queue.isEmpty {
    let (x, y) = queue.removeFirst()
    
    for i in 0..<4 {
        let nx = x + dx[i]
        let ny = y + dy[i]
        
        // 미로 찾기 공간을 벗어난 경우 무시
        if nx < 0 || ny < 0 || nx >= N || ny >= M { continue }
        
        // 벽일 경우 무시
        if graph[nx][ny] == 0 { continue }
        
        // 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
        if graph[nx][ny] == 1 {
            graph[nx][ny] = graph[x][y] + 1
            queue.append((nx, ny))
        }
    }
}

print(graph[N-1][M-1])

// 메모리 : 79672 KB, 시간 : 16 ms
