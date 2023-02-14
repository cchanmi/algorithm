//
//  boj_11047.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/08.
//
//  동전 0
//  https://www.acmicpc.net/problem/11047

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let number = input[0]
var result = input[1]
var array = [Int]()
var count = 0

for _ in 0..<number {
    array.append(Int(readLine()!)!)
}

array.sort(by: >)

for i in array {
        if i <= result {
            let divide = result / i
            count += divide
            result %= i
            if result == 0 {
                print(count)
        }
    }
}

// 메모리 : 69108 KB, 시간 : 8 ms

