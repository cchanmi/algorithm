//
//  boj_1620.swift
//  algorithm
//
//  Created by 황찬미 on 2023/05/18.
//
//  나는야 포켓몬 마스터 이다솜
//  https://www.acmicpc.net/problem/1620

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let number = input[0]
let cutLine = input[1]
var numberKeyDic = [Int:String]()
var nameKeyDic = [String:Int]()


// 딕셔너리에 값 추가

for i in 1...number {
    let input = readLine()!
    numberKeyDic[i, default: ""] += input
    nameKeyDic[input, default: 0] += i
}

// 찾아야 하는 포켓몬 이름이나, 도감 순서일 경우 나눠서 계산

for _ in 0..<cutLine {
    let input = readLine()!
    
    // 도감 순서일 경우
    if let dicNumber = Int(input) {
        print(numberKeyDic[dicNumber]!)
        continue
    }
    
    let poketmonName = input
    print(nameKeyDic[poketmonName]!)
    
}

// 메모리 : 92144 KB, 시간 : 332 ms
