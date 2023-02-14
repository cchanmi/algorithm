//
//  boj_1303.swift
//  algorithm
//
//  Created by 황찬미 on 2023/01/24.
//
//  전쟁 - 전투
//  https://www.acmicpc.net/problem/1303

import Foundation

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let M = input[1]
var graph = [[Character]]()
var visit = Array(repeating: Array(repeating: false, count: N), count: M)

let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

for _ in 0..<M {
    graph.append(Array(readLine()!))
}

var answer: [Character: Int] = ["W": 0, "B": 0]
var count = 0

for i in 0..<M {
    for j in 0..<N {
        if !visit[i][j] {
            count = 0
            dfs(i, j, graph[i][j])
            answer[graph[i][j]]! += count * count
        }
    }
}

func dfs(_ x: Int, _ y: Int, _ c: Character) {
    visit[x][y] = true
    count += 1
    
    for i in 0..<4 {
        let nx = x + dx[i]
        let ny = y + dy[i]
        
        // nx, ny가 전투 공간에 포함된 경우, 방문하지 않았을 경우, 그래프의 문자와 같을 경우
        if 0..<M ~= nx && 0..<N ~= ny && !visit[nx][ny] && graph[nx][ny] == c {
            dfs(nx, ny, c)
        }
    }
}

print(answer["W"]!, answer["B"]!)

// 메모리 : 79652 KB, 시간 : 16 ms
