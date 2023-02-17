//
//  boj_1012.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/14.
//
//  유기농 배추
//  https://www.acmicpc.net/problem/1012

let testCase = Int(readLine()!)!
let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

for _ in 0..<testCase {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    let width = input[0]
    let length = input[1]
    let cabbage = input[2]
    var graph = Array(repeating: Array(repeating: 0, count: width), count: length)
    var visited = Array(repeating: Array(repeating: false, count: width), count: length)
    var count = 0
    
    for _ in 0..<cabbage {
        let input = readLine()!.split(separator: " ").map{Int(String($0))!}
        let x = input[0]
        let y = input[1]
        graph[y][x] = 1
    }
    
    for i in 0..<width {
        for j in 0..<length {
            // 배추가 심어져 있는 위치이며, 방문하지 않았을 경우
            if graph[j][i] == 1 && !visited[j][i] {
                visited[j][i] = true
                dfs(j, i)
                // 간선이 끊기는 위치
                count += 1
            }
        }
    }
    
    print(count)
    
    func dfs(_ y: Int, _ x: Int) {
        for i in 0..<4 {
            let nx = dx[i] + x
            let ny = dy[i] + y
            
            // 그래프 범위를 벗어나지 않고, 배추가 심어져 있는 위치이며, 방문하지 않았을 경우
            if 0..<width ~= nx && 0..<length ~= ny && graph[ny][nx] == 1 && !visited[ny][nx] {
                visited[ny][nx] = true
                dfs(ny, nx)
            }
        }
    }
}

// 메모리 : 69492 KB, 시간 : 16 ms
