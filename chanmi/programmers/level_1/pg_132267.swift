//
//  pg_132267.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/14.
//
//  https://school.programmers.co.kr/learn/courses/30/lessons/132267
//  콜라 문제

import Foundation

func solution(_ a:Int, _ b:Int, _ n:Int) -> Int {
    var n = n
    var cola = 0
    
    while n >= a {
        cola += (n/a)*b
        n = (n/a)*b + (n%a)
    }
    return cola
}

_ = solution(2, 1, 20)
