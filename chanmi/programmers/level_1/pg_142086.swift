//
//  pg_142086.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/04.
//
//  가장 가까운 같은 글자
//  https://school.programmers.co.kr/learn/courses/30/lessons/142086

import Foundation

func solution(_ s:String) -> [Int] {
    var dictionary = [String:Int]()
    let sArray = s.map{String($0)}
    var resultArray = [Int]()
    
    for i in 0..<sArray.count {
        if let value = dictionary[sArray[i]] {
            let result = i-value
            resultArray.append(result)
            dictionary[sArray[i], default: 0] = i
        } else {
            // dictionary에 해당 key에 대한 value가 없을 때
            dictionary[sArray[i], default: 0] = i
            resultArray.append(-1)
            continue
        }
    }
    return resultArray
}

_ = solution("banana", [-1, -1, -1, 2, 2, 2])
