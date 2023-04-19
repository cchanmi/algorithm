//
//  pg_42888.swift
//  algorithm
//
//  Created by 황찬미 on 2023/04/20.
//
//  2019 KAKAO BLIND RECRUITMENT - 오픈채팅방
//  https://school.programmers.co.kr/learn/courses/30/lessons/42888

import Foundation

func solution(_ record:[String]) -> [String] {
    var count = record.count
    var dic = [String:String]()
    var recordArray = Array(repeating: [String](), count: count)
    var result = [String]()
    
    for i in 0..<count {
        recordArray[i] = record[i].split(separator: " ").map{String($0)}
    }
    
    for i in 0..<count {
        // Leave일 경우 index error 방지
        if recordArray[i].count == 2 {
            recordArray[i].append("")
            continue
        }
        
        let action = recordArray[i][0]
        let id = recordArray[i][1]
        let nickname = recordArray[i][2]
        
        if action == "Enter" {
            dic[id, default: nickname] = nickname
        } else if action == "Change" {
            dic[id] = nickname
        }
    }
    
    for i in 0..<count {
        let action = recordArray[i][0]
        let id = recordArray[i][1]
        let nickname = recordArray[i][2]
        
        if action == "Enter" {
            result.append("\(dic[id]!)님이 들어왔습니다.")
        } else if action == "Leave" {
            result.append("\(dic[id]!)님이 나갔습니다.")
        } else {
            continue
        }
    }
    
    return result
}

_ solution(["Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"])
