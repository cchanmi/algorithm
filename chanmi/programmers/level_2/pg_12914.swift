//
//  pg_12914.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/27.
//
//  멀리 뛰기
//  https://school.programmers.co.kr/learn/courses/30/lessons/12914#

func solution(_ n:Int) -> Int {
    var array = [0, 1, 2]

    while array.count <= n {
        array.append((array[array.count-1]+array[array.count-2])%1234567)
    }
    
    // n이 1, 2일 때도 고려해야 한다.
    return Int(array[n])
}

_ = solution(2000)

