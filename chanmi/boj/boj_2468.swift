//
//  boj_2468.swift
//  algorithm
//
//  Created by 황찬미 on 2023/01/30.
//
//  안전 영역
//  https://www.acmicpc.net/problem/2468

/*
 물에 잠기는 지역은 배제하고, 물에 잠기지 않은 지역들만 count +
 */

import Foundation

let input = Int(readLine()!)!
var graph = [[Int]]()
var visited = Array(repeating: Array(repeating: false, count: input), count: input)
var queue = [(Int, Int)]()
var maxNumber = 0
var count = 0

// 물의 높이가 0이어서 어느 영역도 물에 잠기지 않을 수 있기 때문에 기본값이 1이어야 함
var result = 1

let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

for _ in 0..<input {
    let number = readLine()!.split(separator: " ").map{Int(String($0))!}
    graph.append(number)

    for i in number {
        if i > maxNumber {
            maxNumber = i
        }
    }
}

// BFS

func bfs(_ x: Int, _ y: Int, _ h: Int) {
    visited[x][y] = true
    queue.append((x, y))

    while !queue.isEmpty {
        let (x, y) = queue.removeFirst()

        for i in 0..<4 {
            let nx = x + dx[i]
            let ny = y + dy[i]

            // 1. 범위를 벗어나지 않으며,
            // 2. 방문하지 않은 집이며,
            // 3. 물에 잠기지 않는 영역일 경우,
            if 0..<input ~= nx && 0..<input ~= ny && !visited[nx][ny] && graph[nx][ny] > h {
                visited[nx][ny] = true
                queue.append((nx, ny))
            }
        }
    }
}

for i in 0...maxNumber {
    // 높이에 따라 매번 값을 초기화
    count = 0
    visited = Array(repeating: Array(repeating: false, count: input), count: input)
    for j in 0..<input {
        for k in 0..<input {
            // 방문하지 않았고, 물에 잠기지 않는 구역일 때
            if !visited[j][k] && graph[j][k] > i {
                count += 1
                visited[j][k] = true
                bfs(j, k, i)
            }
        }
    }

    result = max(result, count)
}

print(result)

// 메모리 : 79516 KB, 시간 : 112 ms
