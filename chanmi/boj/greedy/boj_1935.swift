//
//  boj_1935.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/19.
//
//  후위 표기식 2
//  https://www.acmicpc.net/problem/1935

import Foundation

let N = Int(readLine()!)!
let postfix = readLine()!.map{String($0)}
var array: [Double] = []
var stack: [Double] = []

for _ in 0..<N {
    array.append(Double(readLine()!)!)
}

for i in postfix.indices {
    if postfix[i] == "*" || postfix[i] == "+" || postfix[i] == "-" || postfix[i] == "/" {
        // 마지막으로 꺼낸 값을 두번째 변수에 넣어야 더하기랑 빼기를 해 줄 때 값이 제대로 나온다
        let second: Double = stack.removeLast()
        let first: Double = stack.removeLast()
        var result = Double()
        if postfix[i] == "*" {
            result = first * second
        } else if postfix[i] == "+" {
            result = first + second
        } else if postfix[i] == "-" {
            result = first - second
        } else if postfix[i] == "/" {
            result = first / second
        }
        stack.append(result)
    }
    else {
        // 알파벳일 경우 char형으로 변환 후, 아스키코드로 변환해 준다
        let alphabet = Int(Character(postfix[i]).asciiValue!-65)
        // array의 인덱스에 따라 stack에 해당하는 값을 더해줌
        stack.append(array[alphabet])
    }
}

// 소수점 두 자리로 잘라 주는 문법. Foundation에 내장되어 있는 문법이다.
print(String(format: "%.2f", stack[0]))

// 메모리 : 79512 KB, 시간 : 12 ms

