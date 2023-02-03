//
//  boj_15649.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/03.
//
//  N과 M (1)
//  https://www.acmicpc.net/problem/15649

import Foundation

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let M = input[1]
var array = [Int]()
var visited = Array(repeating: false, count: N+1)
var depth = 0

func backTracking(_ depth: Int) {
    if depth == M {
        print(array.map{String($0)}.joined(separator: " "))
        return
    } else {
        for i in 1...N {
            if !visited[i] {
                visited[i] = true
                array.append(i)
                backTracking(depth+1)
                visited[i] = false
                array.removeLast()
            }
        }
    }
}

backTracking(depth)

// 메모리 : 69108 KB, 시간 : 104 ms
