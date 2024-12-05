//
//  boj_1475.swift
//  algorithm
//
//  Created by 황찬미 on 12/5/24.
//
//  방 번호
//  https://www.acmicpc.net/problem/1475

// 필요한 최소개수, 6이랑 9뒤집어서 사용 가능

var input = readLine()!.map{Int(String($0))!}
var numberArray = Array(repeating: 0, count: 10)

for i in input {
    numberArray[i] += 1
}

numberArray[6] = (numberArray[6]+numberArray[9]+1)/2
numberArray[9] = numberArray[6]

print(numberArray.max()!)
