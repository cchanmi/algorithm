//
//  pg_17682.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/18.
//
//  [1차] 다트 게임 (2018 KAKAO BLIND RECRUITMENT)
//  https://school.programmers.co.kr/learn/courses/30/lessons/17682

import Foundation

func solution(_ dartResult:String) -> Int {
    let dartResult = dartResult.map{String($0)}
    
    var numberArray = [Int]()
    var squareArray = [Int]()
    var optionArray = [String]()
    
    let checkNumber = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"]
    
    var index = 0
    
    while index < dartResult.count-1 {
        var dartStringNumber = ""
        // dart 점수가 10일 수도 있어서, 그러면 두 번 돌아 줘야 하기 때문
        while checkNumber.contains(dartResult[index]) {
            dartStringNumber += dartResult[index]
            index += 1
        }
    
        let dartNumber = Int(dartStringNumber)!
        numberArray.append(dartNumber)
    
        if dartResult[index] == "S" {
         squareArray.append(1)
        } else if dartResult[index] == "D" {
            squareArray.append(2)
        } else {
            squareArray.append(3)
        }
        
        index += 1
        
        // index를 모두 돌았을 때 break (마지막 옵션 문자열이 없을 때)
        if index > dartResult.count-1 {
            optionArray.append("0")
            break
        }
        
        if dartResult[index] == "#" {
            optionArray.append("#")
            index += 1
        } else if dartResult[index] == "*" {
            optionArray.append("*")
            index += 1
        } else {
            optionArray.append("0")
        }
    }
    
    for i in 0..<numberArray.count {
        let number = Double(numberArray[i])
        let square = Double(squareArray[i])
        let optionArray = optionArray[i]
        
        numberArray[i] = Int(pow(number, square))
        
        if optionArray == "*" {
            if i == 0 {
                numberArray[i] *= 2
            } else {
                numberArray[i] *= 2
                numberArray[i-1] *= 2
            }
        } else if optionArray == "#" {
            numberArray[i] = -numberArray[i]
        }
    }
    
    var result = 0
    
    for i in numberArray {
        result += i
    }
    
    return result
}

_ = solution("1D2S3T*")

