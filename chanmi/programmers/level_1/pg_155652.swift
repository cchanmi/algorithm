//
//  pg_155652.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/03.
//
//  둘만의 암호
//  https://school.programmers.co.kr/learn/courses/30/lessons/155652

import Foundation

func solution(_ s:String, _ skip:String, _ index:Int) -> String {
    let alphabet = (0...25)
        .map{String(UnicodeScalar($0+97))}
        .filter{ !skip.contains($0) }
    var result = ""
    
    for i in s {
        result += alphabet[(alphabet.firstIndex(of: String(i))! + index) % alphabet.count]
    }
    
    return result
}

_ = solution("aukks", "wbqd", 5)

