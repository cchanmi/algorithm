//
//  boj_2910.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/17.
//
//  빈도 정렬
//  https://www.acmicpc.net/problem/2910

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let messageLength = input[0]
let messageSize = input[1]
var messageArray = [Int]()
var dictionary = [Int: Int]()
messageArray = readLine()!.split(separator: " ").map{Int(String($0))!}
var result = [Int]()

for i in messageArray {
    dictionary[i, default: 0] += 1
}

// 횟수가 많은 것부터 출력, 만약 횟수가 같을 경우 먼저 나온 것부터 출력

for (key, value) in dictionary.sorted(by: {
    // 빈도가 같다면
    if $0.value == $1.value {
        // 앞에 있는 것부터 정렬
        return messageArray.firstIndex(of: $0.key)! < messageArray.firstIndex(of: $1.key)!
    }
    return $0.value > $1.value
}) {
    for _ in 0..<value {
        result.append(key)
    }
}

print(result.map{String($0)}.joined(separator: " "))

// 메모리 : 69116 KB, 시간 : 12 ms
