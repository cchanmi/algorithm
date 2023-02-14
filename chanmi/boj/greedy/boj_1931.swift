//
//  boj_1931.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/13.
//
//  회의실 배정
//  https://www.acmicpc.net/problem/1931

let number = Int(readLine()!)!
var array = [(Int, Int)]()

for _ in 0..<number {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    array.append((input[0], input[1]))
}

array.sort(by: {$0.0 < $1.0})
array.sort(by: {$0.1 < $1.1})

var endTime = array[0].1
var count = 1
var result = 0

for i in 1..<array.count {
        if endTime <= array[i].0 {
            endTime = array[i].1
            count += 1
        }
}

print(count)

// 메모리 : 72240 KB, 시간 : 168 ms
