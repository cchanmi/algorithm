//
//  pg_147355.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/04.
//
//  크기가 작은 부분 문자열
//  https://school.programmers.co.kr/learn/courses/30/lessons/147355

import Foundation

func solution(_ t:String, _ p:String) -> Int {
    let pCount = p.count
    let tCount = t.count
    let indexRange = tCount-(pCount-1)
    var result = 0
    
    for i in 0..<indexRange {
        let startIndex = t.index(t.startIndex, offsetBy: i)
        let endIndex = t.index(t.startIndex, offsetBy:i+pCount-1)
        let number = Int(t[startIndex...endIndex])!
        result += number <= Int(p)! ? 1 : 0
    }
    
    return result
}
