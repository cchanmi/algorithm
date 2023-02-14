//
//  boj_2331.swift
//  algorithm
//
//  Created by 황찬미 on 2023/01/26.
//
//  반복수열
//  https://www.acmicpc.net/problem/2331

import Foundation

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let A = input[0]
let P = input[1]
var resultArray = [Int]()
var nowNumber = A
    
while !resultArray.contains(nowNumber) {
    resultArray.append(nowNumber)
    // 57을 5랑 7인 String 값으로 변환하고, 다시 Int형으로 배열에 담음
    let array: [Int] = String(nowNumber).map{Int(String($0))!}
    nowNumber = 0
    // 자리수별로 제곱근을 곱하여 더해줌
    for i in array {
        nowNumber += Int(pow(Double(i), Double(P)))
    }
    // 그러다 중복값을 발견했을 경우 while문 통과
}

for (count, number) in resultArray.enumerated() {
    if number == nowNumber {
        print(count)
    }
}

// 메모리 : 79516 KB, 시간 : 20 ms
