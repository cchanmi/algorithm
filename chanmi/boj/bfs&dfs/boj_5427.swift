//
//  boj_5427.swift
//  algorithm
//
//  Created by 황찬미 on 2023/03/20.
//
//  불
//  https://www.acmicpc.net/problem/5427

let testCase = Int(readLine()!)!

for _ in 0..<testCase {
    let input = readLine()!.split(separator: " ").map{Int(String($0))!}
    let width = input[0]
    let height = input[1]
    var graph = [[String]]()
    
    var queue = [(Int, Int)]()
    var fireQueue = [(Int, Int)]()
    
    let dx = [-1, 1, 0, 0]
    let dy = [0, 0, -1, 1]
    
    // 시작 위치와 방문 체크, 불 위치 큐에 담기
    for i in 0..<height {
        let input = readLine()!.map{String($0)}
        graph.append(input)
        
        for j in 0..<width {
            if input[j] == "@" {
                queue.append((i, j))
            } else if input[j] == "*" {
                fireQueue.append((i, j))
            }
        }
    }
    
    var fireIndex = 0
    var queueIndex = 0
    var count = 0
    var flag = false
    
    f: while queue.count > queueIndex {
        count += 1
    
        // 불 이동하기
        // 불의 개수만큼 for문을 돌아야 함.
        let fireCount = fireQueue.count
    
        while fireIndex < fireCount {
            let (y, x) = fireQueue[fireIndex]
            fireIndex += 1
        
            for i in 0..<4 {
                let nx = dx[i] + x
                let ny = dy[i] + y
            
                if 0..<width ~= nx && 0..<height ~= ny && graph[ny][nx] != "#" && graph[ny][nx] != "*" {
                    graph[ny][nx] = "*"
                    fireQueue.append((ny, nx))
                }
            }
        }
    
        // 상근이 이동하기
        let queueCount = queue.count
    
        while queueIndex < queueCount {
            let (y, x) = queue[queueIndex]
            queueIndex += 1
        
            for i in 0..<4 {
                let nx = dx[i] + x
                let ny = dy[i] + y
            
                if 0..<width ~= nx && 0..<height ~= ny {
                    if graph[ny][nx] == "." {
                        graph[ny][nx] = "@"
                        queue.append((ny, nx))
                    }
                } else {
                    print(count)
                    flag = true
                    break f
                }
            }
        }
    }
    if !flag {
        print("IMPOSSIBLE")
    }
}

// 메모리 : 127428 KB, 시간 : 236 ms

/*
 
 반례
 1
 3 3
 .@#
 .**
 ***
 
 */
