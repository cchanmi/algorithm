//
//  pg_62048.swift
//  algorithm
//
//  Created by 황찬미 on 2023/05/18.
//  멀쩡한 사각형
//  https://school.programmers.co.kr/learn/courses/30/lessons/62048

func solution(_ w:Int, _ h:Int) -> Int64{
    let totalRect = w*h
    
    func gcd(_ a: Int, _ b: Int) -> Int {
        if b == 0 {
            return a
        } else {
            return gcd(b, a%b)
        }
    }
    
    return Int64(totalRect-(w+h-gcd(w, h)))
}

_ = solution(8, 12)
