//
//  pg_42889.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/20.
//
//  실패율 (2019 KAKAO BLIND RECRUITMENT)
//  https://school.programmers.co.kr/learn/courses/30/lessons/42889

import Foundation

func solution(_ N:Int, _ stages:[Int]) -> [Int] {
    var stageCount = stages.count
    var countArray = Array(repeating: 0, count: N+2)
    var dic = [Int:Double]()
    
    // 1부터 N까지의 값 count
    for i in stages {
        countArray[i] += 1
    }
    
    for stage in 1...N {
        let count = countArray[stage]
        if countArray[stage] == 0 {
            dic[stage] = 0.0
        } else {
            dic[stage] = (Double(count)/Double(stageCount))
            stageCount -= count
        }
    }
    
    var resultArray = [Int]()
    
    resultArray = dic.sorted {
        if $0.1 == $1.1 {
            return $0.0 < $1.0
        }
        return $0.1 > $1.1
    }
    .map{$0.0}
    
    return resultArray
}

print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))
