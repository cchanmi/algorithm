//
//  pg_140108.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/06.
//
//  문자열 나누기
//  https://school.programmers.co.kr/learn/courses/30/lessons/140108

import Foundation

func solution(_ s:String) -> Int {
    var x = ""
    var countArray = [0, 0]
    var result = 0
    
    for i in 0..<s.count {
        if x == "" {
            x = String(s[s.index(s.startIndex, offsetBy: i)])
            countArray[0] += 1
        } else {
            if x == String(s[s.index(s.startIndex, offsetBy: i)]) {
                countArray[0] += 1
            } else {
                countArray[1] += 1
            }
            
            if countArray[0] == countArray[1] {
                result += 1
                x = ""
                countArray = [0, 0]
            }
        }
    }
    
    // countArray의 개수는 다르지만 값이 남아 있을 경우 count += 1 해 주어야 함
    if x != "" { result += 1 }
    
    return result
}

_ = solution("banana")
