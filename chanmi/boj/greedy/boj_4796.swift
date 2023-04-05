//
//  boj_4796.swift
//  algorithm
//
//  Created by 황찬미 on 2023/04/05.
//
//  캠핑
//  https://www.acmicpc.net/problem/4796

var i = 1

while true {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    if input.reduce(0, +) == 0 { break }
    
    let L = input[0]
    let P = input[1]
    let V = input[2]
    var result = 0
    
    result += (V/P)*L + min(L, V%P)
    
    print("Case \(i): \(result)")
    i += 1
}

// 메모리 : 69104 KB, 시간 : 12 ms
