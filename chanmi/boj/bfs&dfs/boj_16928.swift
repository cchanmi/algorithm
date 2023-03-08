//
//  boj_16928.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/08.
//
//  뱀과 사다리 게임
//  https://www.acmicpc.net/problem/16928

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let ladder = input[0]
let snake = input[1]
var queue = [(Int, Int)]()
var graph = Array(repeating: 0, count: 101)
var visited = Array(repeating: false, count: 101)
var result = Int.max

for _ in 0..<ladder+snake {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    graph[input[0]] = input[1]
}

visited[1] = true
var index = 0

func bfs(_ start: Int, _ count: Int) {
    var queue = [(Int, Int)]()
    queue.append((start, count))
    
    while queue.count > index {
        let (now, nowCount) = queue[index]
        index += 1
        
        for i in 1...6 {
            var next = now+i
            print(next)
            if next == 100 {
                result = max(result, nowCount+1)
                return
            } else if next < 100 {
                while graph[next] != 0 {
                    next = graph[next]
                }
                if !visited[next] {
                    queue.append((next, nowCount+1))
                    visited[next] = true
                }
            }
        }
    }
}

bfs(1, 0)
print(result)

// 메모리 : 69108 KB, 시간 : 12 ms
