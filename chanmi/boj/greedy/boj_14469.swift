//
//  boj_14469.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/07.
//
//  소가 길을 건너간 이유 3
//  https://www.acmicpc.net/problem/14469

import Foundation

let input = Int(readLine()!)!
var cowArray = [(Int, Int)]()
var result = 0

for _ in 0..<input {
    let inputCow = readLine()!.split(separator: " ").map{Int(String($0))!}
    cowArray.append((inputCow[0], inputCow[1]))
}

// 첫번째 거 기준으로 정렬
cowArray.sort(by: <)

for i in 0..<input {
    // 대기하는 소가 있을 경우
    if result > cowArray[i].0 {
        result += cowArray[i].1
    // 대기하는 소가 없을 경우
    } else {
        result = cowArray[i].0 + cowArray[i].1
    }
}

print(result)

// 메모리 : 69108 KB, 시간 : 8 ms
