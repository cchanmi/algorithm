//
//  pg_135808.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/13.
//
//  과일 장수
//  https://school.programmers.co.kr/learn/courses/30/lessons/135808

import Foundation

func solution(_ k:Int, _ m:Int, _ score:[Int]) -> Int {
    let i = score.count%m
    var sortedScore = score.sorted(by: >)[0..<score.count-i]
    var result = 0
    
    for i in stride(from: 0, to: score.count-i, by: m) {
        result += Array(sortedScore[i..<i+m]).min()!*m
}
    return result
}

_ = solution(4, 3, [4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2])
