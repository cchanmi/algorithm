//
//  boj_2206.swift
//  algorithm
//
//  Created by 황찬미 on 8/5/24.
//
//  벽 부수고 이동하기
//  https://www.acmicpc.net/problem/2206

// bfs로 접근해야 하는데 벽을 한개까지는 뿌셔도 됨
// 이게 의미하는것은? -> visited 배열을 3차원으로 접근해서 벽을 뿌셨는지 아닌지를 판단함.

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let n = input[0]
let m = input[1]
var graph = Array(repeating: Array(repeating: 0, count: m), count: n)
var visited = Array(repeating: Array(repeating: Array(repeating: false, count: m), count: n), count: 2)

for i in 0..<n {
    let input = readLine()!.map{Int(String($0))!}
    graph[i] = input
}

// 처음 위치
var queue = [(y: 0, x: 0, count: 1, broken: 0)]

// 벽을 안 부순 상태이기 때문에 0일 때
visited[0][0][0] = true
var index = 0

let dy = [-1, 1, 0, 0]
let dx = [0, 0, -1, 1]

var result = -1

while queue.count > index {
    let (nowY, nowX, nowCount, nowBroken) = queue[index]
    index += 1
    
    if nowY == n-1 && nowX == m-1 {
        result = nowCount
        break
    }
    
    for i in 0..<4 {
        let ny = nowY+dy[i]
        let nx = nowX+dx[i]
        
        if 0..<n ~= ny && 0..<m ~= nx && !visited[nowBroken][ny][nx] {
            
            if graph[ny][nx] == 0 {
                visited[nowBroken][ny][nx] = true
                queue.append((ny, nx, nowCount+1, nowBroken))
            } else if graph[ny][nx] == 1 && nowBroken == 0 {
                visited[1][ny][nx] = true
                queue.append((ny, nx, nowCount+1, 1))
            }
        }
    }
}

print(result)
