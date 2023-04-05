//
//  boj_1449.swift
//  algorithm
//
//  Created by 황찬미 on 2023/04/06.
//
//  수리공 항승
//  https://www.acmicpc.net/problem/1449

/*
 새로운 테이프를 사용하기 위한 조건을 잘 생각해 보자
 */

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let L = input[1]
var graph = readLine()!.split(separator: " ").map{Int(String($0))!}
var count = 0
var start = 0

graph.sort()

for i in 0..<graph.count {
    if i == 0 {
        count += 1
        start = graph[i]
        continue
    }
    
    if graph[i] - start >= L {
        count += 1
        start = graph[i]
    }
}

print(count)

// 메모리 : 69108 KB, 시간 : 8 ms
