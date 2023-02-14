//
//  boj_1541.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/09.
//
//  잃어버린 괄호
//  https://www.acmicpc.net/problem/1541

let input = readLine()!.split(separator: "-")
var sumArray: [Int] = []

for i in input {
    let number = i.split(separator: "+").map{Int($0)!}
    sumArray.append(number.reduce(0, +))
}

// - 부호가 나오기 이전의 값은 모두 양수
var result = sumArray[0]
for i in 1..<sumArray.count {
    result -= sumArray[i]
}

print(result)

// 메모리 : 69104 KB, 시간 : 12 ms
