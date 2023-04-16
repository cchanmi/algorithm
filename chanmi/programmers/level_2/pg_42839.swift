//
//  pg_42839.swift
//  algorithm
//
//  Created by 황찬미 on 2023/04/17.
//
//  소수 찾기
//  https://school.programmers.co.kr/learn/courses/30/lessons/42839

import Foundation

func solution(_ numbers:String) -> Int {
    var primeArray = [Int]()
    let numberArray = numbers.map{String($0)}
    print(numberArray)
    var visited = Array(repeating: false, count: numberArray.count)
    var result = ""
    
    func isPrime(_ number: Int) -> Bool {
        if number < 4 {
            return (number == 1 || number == 0) ? false : true
        } else {
            for i in 2...Int(sqrt(Double(number))) {
                if number % i == 0 {
                    return false
                }
            }
            return true
        }
    }
    
    func dfs(_ string: String, _ depth: Int) {
        if depth == numberArray.count {
            let number = Int(string)!
            if isPrime(number) && !primeArray.contains(number) {
                primeArray.append(number)
            }
        } else {
            for i in 0..<numberArray.count {
                if !visited[i] {
                    visited[i] = true
                    result += numberArray[i]
                    dfs(result, depth+1)
                    visited[i] = false
                    result = string
                }
            }
        }
    }
    
    for i in 0..<numberArray.count {
        dfs(result, i)
    }
    
    return primeArray.count
}

_ = solution("17")
