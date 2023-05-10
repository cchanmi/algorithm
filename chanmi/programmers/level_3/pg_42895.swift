//
//  pg_42895.swift
//  algorithm
//
//  Created by 황찬미 on 2023/05/09.
//
//  N으로 표현
//  https://school.programmers.co.kr/learn/courses/30/lessons/42895

import Foundation

func solution(_ N:Int, _ number:Int) -> Int {

    func dfs(_ now: Int, _ depth: Int) {
        if depth > 8 { return }
        
        if now == number && (result == -1 || depth < result) {
            result = depth
        }
        
        var NN = 0
        
        for i in 0..<8 {
            NN = (NN*10)+N
            
            dfs(now+NN, depth+1+i)
            dfs(now-NN, depth+1+i)
            dfs(now/NN, depth+1+i)
            dfs(now*NN, depth+1+i)
        }
    }
    
    var result = -1
    dfs(0, 0)
    
    return result
}

_ = solution(5, 12)
