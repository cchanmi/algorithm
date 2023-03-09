//
//  pg_136798.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/10.
//
//  기사단원의 무기
//  https://school.programmers.co.kr/learn/courses/30/lessons/136798

import Foundation

func solution(_ number:Int, _ limit:Int, _ power:Int) -> Int {
    var array: [Int] = []
    var result = 0
    for num in 1...number {
        var squrtArray: [Int] = []
        let value = Int(sqrt(Double(num)))
        for squrtValue in 1...value {
            // 구하려는 N의 약수 / 1부터 제곱근까지의 수가 0일 때
            if num % squrtValue == 0 {
                squrtArray.append(squrtValue)
                // 0으로 나누어 떨어졌던 수를 구하려는 N의 약수에 나눈다.
                let n = num/squrtValue
                // 나눈 몫의 값이 중복되지 않을 때
                if !squrtArray.contains(n) {
                    squrtArray.append(n)
                }
            }
        }
        array.append(squrtArray.count)
    }

    for i in array {
        if i <= limit {
            result += i
        } else {
            result += power
        }
    }
    return result
}

_ = solution(10, 3, 2))
