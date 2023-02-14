//
//  boj_15651.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/04.
//
//  N과 M (3)
//  https://www.acmicpc.net/problem/15651

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let M = input[1]
var stack = [Int]()
var result = ""

func backTracking(_ start: Int) {
    if stack.count == M {
        // 기존의 stack.map{String($0)}.joined(separator: " ") 코드로는
        // 값이 나올 때마다 매번 print를 해 주어야 해서 시간 초과가 나온 것 같다
        // 값이 나올 때마다 result에 값을 넣고, 마지막에 한번에 print
        result += stack.map{String($0)}.joined(separator: " ")
        result += "\n"
        return
    }
    for i in 1...N {
        stack.append(i)
        backTracking(i+1)
        stack.removeLast()
    }
}

backTracking(1)
print(result)

// 메모리 : 100600 KB, 시간 : 916 ms
