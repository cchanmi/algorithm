//
//  boj_14940.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/17.
//
//  쉬운 최단거리
//  https://www.acmicpc.net/problem/14940

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let height = input[0]
let width = input[1]
var graph = [[Int]]()
var queue = [(Int, Int, Int)]()
var visited = Array(repeating: Array(repeating: false, count: width), count: height)

for _ in 0..<height {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    graph.append(input)
}

for i in 0..<height {
    for j in 0..<width {
        if graph[i][j] == 2 {
            queue.append((i, j, 0))
            graph[i][j] = 0
            visited[i][j] = true
            break
        }
    }
}

var index = 0

let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

func bfs() {
    while queue.count > index {
        let (y, x, count) = queue[index]
        index += 1
        
        for i in 0..<4 {
            let nx = dx[i] + x
            let ny = dy[i] + y
            
            if 0..<width ~= nx && 0..<height ~= ny && graph[ny][nx] != 0 && !visited[ny][nx] {
                graph[ny][nx] = count+1
                visited[ny][nx] = true
                queue.append((ny, nx, count+1))
            }
        }
    }
}

bfs()

// 갈 수 있는 땅인데, 도달할 수 없을 경우
for i in 0..<height {
    for j in 0..<width {
        if graph[i][j] == 1 && !visited[i][j] {
            graph[i][j] = -1
        }
    }
}

for i in 0..<height {
    print(graph[i].map{String($0)}.joined(separator: " "))
}
