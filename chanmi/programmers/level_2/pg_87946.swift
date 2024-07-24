//
//  pg_87946.swift
//  algorithm
//
//  Created by 황찬미 on 7/24/24.
//
// 피로도
// https://school.programmers.co.kr/learn/courses/30/lessons/87946

import Foundation

func solution(_ k:Int, _ dungeons:[[Int]]) -> Int {
    
    var result = Int.min
    var visited = Array(repeating: false, count: dungeons.count)
    
    func dfs(now: Int, count: Int) {
        result = max(count, result)
        
        for i in 0..<dungeons.count {
            if now >= dungeons[i][0] && !visited[i] {
                visited[i] = true
                dfs(now: now-dungeons[i][1], count: count+1)
                visited[i] = false
            }
        }
    }
    
    for i in 0..<dungeons.count {
        dfs(now: k, count: 0)
    }
    
    return result
}
