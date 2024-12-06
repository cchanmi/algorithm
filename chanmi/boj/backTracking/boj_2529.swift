//
//  boj_2529.swift
//  algorithm
//
//  Created by 황찬미 on 12/6/24.
//
//  부등호
//  https://www.acmicpc.net/status?user_id=gkfn980&problem_id=2529&from_mine=1

let k = Int(readLine()!)!
let booho = readLine()!.split(separator: " ").map{String($0)}
var numberArray: [Int] = []
var visited = Array(repeating: false, count: 10)

for i in 0...9 {
    numberArray.append(i)
}

var resultArray: [String] = []

func dfs(depth: Int, now: [String]) {
    // 여기서 부호에 맞게 진행 중인지 조건 걸었다가, 너무 많은 재귀 호출로 시간 초과
    if depth == k+1 {
        resultArray.append(now.map{String($0)}.joined())
        return
    }
    
    for i in 0..<numberArray.count {
        if !visited[i] {
            // 현재 부호에 맞게 진행 중인지 검사 필요함
            if depth > 0 {
                if booho[depth-1] == "<" && Int(now[depth-1])! > numberArray[i] {
                    continue
                } else if booho[depth-1] == ">" && Int(now[depth-1])! < numberArray[i] {
                    continue
                }
            }
            
            visited[i] = true
            dfs(depth: depth+1, now: now+[String(numberArray[i])])
            visited[i] = false
        }
    }
}

dfs(depth: 0, now: [])
print(resultArray.max()!)
print(resultArray.min()!)

