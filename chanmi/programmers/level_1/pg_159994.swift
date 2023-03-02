//
//  pg_159994.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/02.
//
//  카드 뭉치
//  https://school.programmers.co.kr/learn/courses/30/lessons/159994

import Foundation

func solution(_ cards1:[String], _ cards2:[String], _ goal:[String]) -> String {
    var card1Index = 0
    var card2Index = 0
    var result = "Yes"
    
    for word in goal {
        if card1Index < cards1.count && cards1[card1Index] == word {
            card1Index += 1
        } else if card2Index < cards2.count && cards2[card2Index] == word {
            card2Index += 1
        } else {
            result = "No"
        }
    }
    
    return result
}

_ = solution(["i", "drink", "water"], ["want", "to"], ["i", "want", "to", "drink", "water"])
