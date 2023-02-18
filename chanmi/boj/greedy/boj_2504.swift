//
//  boj_2504.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/18.
//
//  괄호의 값
//  https://www.acmicpc.net/problem/2504

let inputString = readLine()!.map{String($0)}
var stack = [String]()
var temp = 1
var result = 0
var isError = false

for i in inputString.indices {
    if inputString[i] == "(" {
        temp *= 2
        stack.append(inputString[i])
    } else if inputString[i] == "[" {
        temp *= 3
        stack.append(inputString[i])
    } else if inputString[i] == ")" {
        // ")"가 들어왔을 경우, 스택이 비어 있거나, 스택의 마지막 값이 "("이 아니라면 error
        // 반복문 빠져나옴
        if stack.isEmpty || stack.last != "(" {
            isError = true
            break
        // ")"가 들어왔을 경우, 그전의 인덱스가 "("라면 result에 현재 temp 더하기
        } else if inputString[i-1] == "(" {
            result += temp
        }
        // 스택에서 가장 마지막에 있는 값 빼주기
        temp /= 2
        stack.removeLast()
    } else if inputString[i] == "]" {
        if stack.isEmpty || stack.last != "[" {
            isError = true
            break
        } else if inputString[i-1] == "[" {
            result += temp
        }
        temp /= 3
        stack.removeLast()
    }
}

// 스택이 비어 있지 않거나, isError가 true인 경우 0 출력, 아닐 경우 result 출력
(!stack.isEmpty || isError ) ? print(0) : print(result)

// 메모리 : 69100 KB, 시간 : 8 ms
