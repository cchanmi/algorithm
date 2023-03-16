//
//  pg_77484.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/16.
//
//  로또의 최고 순위와 최저 순위
//  https://school.programmers.co.kr/learn/courses/30/lessons/77484

import Foundation

func solution(_ lottos:[Int], _ win_nums:[Int]) -> [Int] {
    var removeLotto = 0
    var minResult = 0
    let ranking = [6, 6, 5, 4, 3, 2, 1]
    
    for i in lottos {
        if i == 0 {
            removeLotto += 1
        } else {
            for j in win_nums {
                if i == j {
                    minResult += 1
                }
            }
        }
    }
    
    let maxResult = minResult+removeLotto
    
    return [ranking[maxResult], ranking[minResult]]
}

_ = solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19])
