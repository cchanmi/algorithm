//
//  boj_11000.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/13.
//
//  강의실 배정
//  https://www.acmicpc.net/problem/11000

let number = Int(readLine()!)!
var classTime = [(Int, Int)]()

for _ in 0..<number {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    classTime.append((input[0], input[1]))
}

// 강의 시작순으로 정렬
classTime.sort(by: <)

// 첫번째 강의가 끝나는 시간을 기준으로 시작
var classRoom = [classTime[0].1]
var endTime = classTime[0].1

for i in 1..<number {
    // 강의가 끝나는 시간보다 같거나 클 때
    if classTime[i].0 >= endTime {
        // 배열에 있는 값을 지우고, 끝나는 시간을 새로 갱신해 준다
        classRoom.remove(at: endTime)
        endTime = classTime[i].1
    }
    
    // 현재 강의가 끝나는 시간보다 작을 때, 강의실이 하나 더 필요한 것이기 때문에
    // classRoom 배열에 값 append 후
    // 끝나는 시간을 기준으로 정렬
    classRoom.append(classTime[i].1)
    classRoom.sort()
}

print(classRoom.count)

// 시간 초과... 우선순위 큐 문제 ㅠㅠ
