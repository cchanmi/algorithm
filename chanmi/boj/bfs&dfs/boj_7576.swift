//
//  boj_7576.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/24.
//
//  토마토
//  https://www.acmicpc.net/problem/7576

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let M = input[0]
let N = input[1]
var queue = [(Int, Int, Int)]()
var graph = [[Int]]()
var result = 0

for _ in 0..<N {
    graph.append(readLine()!.split(separator: " ").map{Int(String($0))!})
}

for i in 0..<N {
    for j in 0..<M {
        if graph[i][j] == 1 {
            queue.append((i, j, 0))
        }
    }
}

let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

var index = 0
while index < queue.count {
    let (y, x, day) = queue[index]
    index += 1
    
    for i in 0..<4 {
        let nx = dx[i] + x
        let ny = dy[i] + y
        let nextDay = day + 1
        
        if 0..<M ~= nx && 0..<N ~= ny && graph[ny][nx] == 0 {
            graph[ny][nx] = 1
            queue.append((ny, nx, nextDay))
            result = nextDay
        }
    }
}

for i in 0..<N {
    if graph[i].contains(0) {
       result = -1
    }
}

print(result)

// 메모리 : 114628 KB, 시간 : 320 ms
