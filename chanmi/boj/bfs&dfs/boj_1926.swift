//
//  boj_1926.swift
//  algorithm
//
//  Created by 황찬미 on 12/5/24.
//
// 그림
// https://www.acmicpc.net/problem/1926

let input = readLine()!.split(separator: " ").map{Int($0)!}
let n = input[0]
let m = input[1]
var graph = Array(repeating: [Int()], count: n)
var visited = Array(repeating: Array(repeating: false, count: m), count: n)

for i in 0..<n {
    let array = readLine()!.split(separator: " ").map{Int($0)!}
    graph[i] = array
}

let dy = [-1, 1, 0, 0]
let dx = [0, 0, -1, 1]

func dfs(startY: Int, startX: Int) -> Int {
    var count = 1
    
    for i in 0..<4 {
        let ny = dy[i] + startY
        let nx = dx[i] + startX
        
        if 0..<n ~= ny && 0..<m ~= nx {
            if !visited[ny][nx] && graph[ny][nx] == 1 {
                visited[ny][nx] = true
                count += dfs(startY: ny, startX: nx)
            }
        }
    }
    
    return count
}

var result = 0
var pictureNumber = 0

for i in 0..<n {
    for j in 0..<m {
        if !visited[i][j] && graph[i][j] == 1 {
            pictureNumber += 1
            visited[i][j] = true
            result = max(result, dfs(startY: i, startX: j))
        }
    }
}

print(pictureNumber)
print(result)
