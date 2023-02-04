//
//  boj_1182.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/04.
//
//  부분수열의 합
//  https://www.acmicpc.net/problem/1182

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let S = input[1]
var number = readLine()!.split(separator: " ").map{Int(String($0))!}
var array = [Int]()
var visited = Array(repeating: false, count: N)
var sum = 0
var count = 0

func backTracking(_ start: Int, _ depth: Int) {
    // 합이기 때문에 depth가 1 이상이라는 조건이 필요함
    if sum == S && depth >= 1 {
        count += 1
    }
    
    for i in start..<N {
        if !visited[i] {
            visited[i] = true
            sum += number[i]
            array.append(number[i])
            backTracking(i, depth+1)
            visited[i] = false
            sum -= number[i]
            array.remove(at: i)
        }
    }
}

backTracking(0, 0)
print(count)

// 메모리 : 69104 KB, 시간 : 96 ms
