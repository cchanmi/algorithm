//
//  pg_42842.swift
//  algorithm
//
//  Created by 황찬미 on 2023/04/17.
//
//  카펫
//  https://school.programmers.co.kr/learn/courses/30/lessons/42842
import Foundation

func solution(_ brown:Int, _ yellow:Int) -> [Int] {
    let sum = brown+yellow
    var array = [0, 0]
    for width in 1...sum-1 {
        if sum % width == 0 {
            let height = sum/width
            // 넓이는 높이보다 무조건 크거나 같기 때문에
            if width < height {continue}
            if (width-2)*(height-2) == yellow {
                array = [width, height]
            }
        }
    }
    return array
}
