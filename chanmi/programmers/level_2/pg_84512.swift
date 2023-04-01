//
//  pg_84512.swift
//  algorithm
//
//  Created by 황찬미 on 2023/04/01.
//
//  모음사전
//  https://school.programmers.co.kr/learn/courses/30/lessons/84512

func solution(_ word:String) -> Int {
    let alphabet = ["A", "E", "I", "O", "U"]
    var flag = false
    var resultCount = 0
    var count = 0
    
    func bruteForce(_ result: String){
        if result == word {
            resultCount = count
            flag = true
            return
        }
        
        if result.count == 5 { return }
        
        for i in 0..<5 {
            if flag { break }
            count += 1
            bruteForce(result+alphabet[i])
        }
    }
    
    bruteForce("")
    
    return resultCount
}

_ = solution("AAAAE")
