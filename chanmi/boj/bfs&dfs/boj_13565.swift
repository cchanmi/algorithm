//
//  boj_13565.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/23.
//
//  침투
//  https://www.acmicpc.net/problem/13565

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let M = input[0]
let N = input[1]
var visited = Array(repeating: Array(repeating: false, count: N), count: M)
var graph = [[Int]]()
var result = "NO"

for _ in 0..<M {
    graph.append(readLine()!.map{Int(String($0))!})
}

let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

// dfs
func dfs(_ y: Int, _ x: Int) {
    visited[y][x] = true
    
    for i in 0..<4 {
        let nx = x + dx[i]
        let ny = y + dy[i]
        
        if 0..<N ~= nx && 0..<M ~= ny && !visited[ny][nx] && graph[ny][nx] == 0 {
            dfs(ny, nx)
        }
    }
}

// 첫번째줄에서 출발하기 때문에, 0번째 인덱스로 출발
for i in 0..<N {
    if !visited[0][i] && graph[0][i] == 0 {
        dfs(0, i)
    }
}

// 마지막 인덱스까지 방문했다면 YES
if visited[M-1].contains(true) { result = "YES"}

print(result)

// 메모리 : 117288 KB, 시간 : 108 ms
