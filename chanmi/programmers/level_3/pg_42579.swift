//
//  pg_42579.swift
//  algorithm
//
//  Created by 황찬미 on 2023/05/11.
//
//  베스트앨범
//  https://school.programmers.co.kr/learn/courses/30/lessons/42579

import Foundation

func solution(_ genres:[String], _ plays:[Int]) -> [Int] {
    
    var dic = [String:[(Int, Int)]]()
    
    for i in 0..<genres.count {
        dic[genres[i], default: []].append((i, plays[i]))
    }
    
    var result = [Int]()
        
    let sortedDic = dic.sorted { (first, second) in
        return first.value.map { $0.1 }.reduce(0, +) > second.value.map { $0.1 }.reduce(0, +)
    }
        
    for (key, value) in sortedDic {
        let temp = value.sorted { (first, second) in
            if first.1 == second.1 {
                return first.0 < second.0
            }
            return first.1 > second.1
        }
            
        dic[key] = temp
        
        for i in 0..<min(temp.count, 2) {
            result.append(temp[i].0)
        }
    }
    
    return result
}

_ = solution(["classic", "pop", "classic", "classic", "pop"], [500, 600, 150, 800, 2500])
