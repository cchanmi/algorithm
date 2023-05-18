//
//  boj_9375.swift
//  algorithm
//
//  Created by 황찬미 on 2023/05/18.
//
//  패션왕 신해빈
//  https://www.acmicpc.net/problem/9375

let testCase = Int(readLine()!)!

for _ in 0..<testCase {
    let number = Int(readLine()!)!
    var dic = [String:[String]]()
    
    for _ in 0..<number {
        let word = readLine()!.split(separator: " ").map{String($0)}
        dic[word[1], default: []].append(word[0])
    }
    
    var result = 1
    
    for (_, value) in dic {
        result *= (value.count+1)
    }
    
    print(result-1)
}
