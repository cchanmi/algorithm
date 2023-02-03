//
//  boj_15650.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/03.
//
//  N과 M (2)
//  https://www.acmicpc.net/problem/15650

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let M = input[1]
var stack = [Int]()
var visited = Array(repeating: false, count: N+1)

func backTracking(_ start: Int) {
    if stack.count == M {
        print(stack.map{String($0)}.joined(separator: " "))
        return
    } else {
        // start가 N보다 커질 경우가 있는데, 그것을 방지.
        if start <= N {
            // startq부터 for문을 돈다. start보다 작은 값은 방문하지 않음.
            for i in start...N {
                if !visited[i] && start <= N {
                    visited[i] = true
                    stack.append(i)
                    backTracking(i+1)
                    visited[i] = false
                    stack.removeLast()
                }
                
            }
        }
    }
}

backTracking(1)

// 메모리 : 69108 KB, 시간 : 8 ms
