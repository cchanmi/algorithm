//
//  pg_133502.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/13.
//
//  햄버거 만들기
//  https://school.programmers.co.kr/learn/courses/30/lessons/133502

import Foundation

func solution(_ ingredient:[Int]) -> Int {
    var result = 0
    var stack = [Int]()
    
    for i in 0..<ingredient.count {
        stack.append(ingredient[i])
        
        if stack.count > 3 {
            if stack[stack.count-1] == 1 && stack[stack.count-2] == 3 && stack[stack.count-3] == 2 && stack[stack.count-4] == 1 {
                stack.removeLast()
                stack.removeLast()
                stack.removeLast()
                stack.removeLast()
                result += 1
            }
        }
    }
    return result
}

_ = solution([2, 1, 1, 2, 3, 1, 2, 3, 1])
