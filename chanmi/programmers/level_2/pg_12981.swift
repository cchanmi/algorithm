//
//  pg_12981.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/20.
//
//  영어 끝말잇기 - Summer/Winter Coding(~2018)
//  https://school.programmers.co.kr/learn/courses/30/lessons/12981

import Foundation

func solution(_ n:Int, _ words:[String]) -> [Int] {
    var dic = [words[0]: true]
    
    for i in 1..<words.count {
        if dic[words[i]] == true || words[i-1].last != words[i].first {
            return [i%n+1, i/n+1]
        }
        dic[words[i]] = true
    }
    
    return [0, 0]
}
