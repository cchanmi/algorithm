//
//  boj_1918.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/20.
//
//  후위 표기식
//  https://www.acmicpc.net/problem/1918

let input = readLine()!.map{String($0)}
var stack = [String]()
var result = [String]()

for i in input.indices {
    // 열린 괄호일 때
    if input[i] == "(" {
        stack.append(input[i])
    // 닫힌 괄호일 때
    } else if input[i] == ")" {
        while !stack.isEmpty && stack.last != "(" {
            result.append(stack.removeLast())
        }
        // 열린 괄호 빼기 )
        stack.removeLast()
    } else if input[i] == "*" || input[i] == "/" {
        // +나 /일 때, 스택의 마지막 값이 *나 /일 경우 먼저 계산해 주어야 해서 스택에서 빼야 한다.
        while !stack.isEmpty && (stack.last == "*" || stack.last == "/") {
            result.append(stack.removeLast())
        }
        stack.append(input[i])
    } else if input[i] == "+" || input[i] == "-" {
        // +나 -일 때 우선순위가 제일 높고, stack의 마지막 값이 연산자일 경우 stack.removeLast() 반복
        while !stack.isEmpty && stack.last != "(" {
            result.append(stack.removeLast())
        }
        stack.append(input[i])
        // 알파벳일 경우 바로 result에 삽입
    } else {
        result.append(input[i])
    }
 }

// stack에 연산자가 남아 있을 경우
while !stack.isEmpty {
    result.append(stack.removeLast())
}

print(result.map{String($0)}.joined(separator: ""))

// 메모리 : 69100 KB, 시간 : 8 ms
