//
//  boj_1759.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/03.
//
//  암호 만들기
//  https://www.acmicpc.net/problem/1759

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let L = input[0]
let C = input[1]
let aeiou = ["a", "e", "i", "o", "u"]
let vowel = ["b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x", "y", "z"]
var password = readLine()!.split(separator: " ").map{String($0)}
var visited = Array(repeating: false, count: C)
var result = [String]()
password.sort()

// 이전의 index는 돌지 않아야 하고, 최소 한개의 모음, 최소 두 개의 자음을 가지고 있는지 확인해야 됨.
func backTracking(_ start: Int, depth: Int) {
    if depth == L {
        var aeiouContain = 0
        var vowelCount = 0
        for i in aeiou {
            if result.contains(i) {
                aeiouContain += 1
            }
        }
        
        for i in vowel {
            if result.contains(i) {
                vowelCount += 1
            }
        }
        
        if aeiouContain >= 1 && vowelCount >= 2 {
            print(result.map{String($0)}.joined())
            return
        }
    } else {
        for i in start..<C {
            if !visited[i] {
                visited[i] = true
                result.append(password[i])
                backTracking(i, depth: depth+1)
                visited[i] = false
                result.removeLast()
            }
        }
    }
}

backTracking(0, depth: 0)

// 메모리 : 69112 ms 시간 : 24 ms

