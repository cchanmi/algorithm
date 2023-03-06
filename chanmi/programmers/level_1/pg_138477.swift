//
//  pg_138477.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/06.
//
//  명예의 전당 (1)
//  https://school.programmers.co.kr/learn/courses/30/lessons/138477

import Foundation

func solution(_ k:Int, _ score:[Int]) -> [Int] {
    var awardArray = [Int]()
    var resultArray = [Int]()
    
    for i in 0..<score.count {
        if i < k {
            awardArray.append(score[i])
            awardArray.sort()
            resultArray.append(awardArray[0])
            continue
        }
        
        if score[i] > awardArray[0] {
            awardArray.removeFirst()
            awardArray.append(score[i])
            awardArray.sort()
            resultArray.append(awardArray[0])
        } else {
            resultArray.append(awardArray[0])
        }
    }
    
    return resultArray
}

_ = solution(3, [10, 100, 20, 150, 1, 100, 200])
