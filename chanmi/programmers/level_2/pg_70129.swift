//
//  pg_70129.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/30.
//
//  이진 변환 반복하기
//  https://school.programmers.co.kr/learn/courses/30/lessons/70129

func solution(_ s:String) -> [Int] {
    var s = s
    var count = 0
    var zeroBitCount = 0
    
    while true {
        let total = s.count
        let oneBitCount = s.filter{ $0 == "1" }.count
        zeroBitCount += total-oneBitCount
        
        s = String(oneBitCount, radix: 2)
        count += 1
        
        // 도달했다면
        if oneBitCount == 1 {
            break
        }
    }
    return [count, zeroBitCount]
}

print(solution("110010101001"))
