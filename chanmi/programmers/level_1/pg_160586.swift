//
//  pg_160586.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/01.
//
//  대충 만든 자판
//  https://school.programmers.co.kr/learn/courses/30/lessons/160586

import Foundation

func solution(_ keymap:[String], _ targets:[String]) -> [Int] {
    var dictionary = [Character: Int]()
    var resultArray = [Int]()
    
    for key in keymap {
        for (index, alphabet) in key.enumerated() {
            dictionary[alphabet] = min(dictionary[alphabet, default: 100], index+1)
        }
    }
    
    for target in targets {
        var result = 0
        for char in target {
            // 딕셔너리에 해당 key의 value가 없다면 else로 빠짐
            if let key = dictionary[char] {
                result += key
            } else {
                result = -1
                break
            }
        }
        resultArray.append(result)
    }
    return resultArray
}

_ = solution(["ABACD", "BCEFD"], ["ABCD","AABB"])
