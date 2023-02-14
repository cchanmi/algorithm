//
//  boj_13458.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/13.
//
//  시험 감독
//  https://www.acmicpc.net/problem/13458

let N = Int(readLine()!)!
let student = readLine()!.split(separator: " ").map{Int(String($0))!}
let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let B = input[0]
let C = input[1]
var count = 0

for i in student {
    var result = 0
    
    result = i - B
    count += 1
    
    // 학생수 - 총감독관의 값이 음수일 경우 넘어감
    // 학생수 나누기 부감독관리 0으로 나누어 떨어질 때, 나누기 몫만큼 count ++
    // 나머지가 남을 때에는 나누기 몫만큼 +1 count ++
    if result > 0 {
        count += result % C == 0 ? (result/C) : (result/C)+1
    } else {
        continue
    }
}

print(count)

// 메모리 : 134296 KB, 시간 : 460 ms
