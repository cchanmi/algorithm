//
//  boj_2583.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/12.
//
//  영역 구하기
//  https://www.acmicpc.net/problem/2583

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let M = input[0] // x : 5
let N = input[1] // y : 7
let K = input[2]
var graph = Array(repeating: Array(repeating: 0, count: N), count: M)
var count = 0
var regionArray = [Int]()

// 문제에서 왼쪽 아래 꼭짓점과 오른쪽 위 꼭짓점을 주었고,
// x좌표와 y좌표를 반대로 해 주어도 결국 같은 그래프이다
// 그래서 graph[j][i]로 반대로 넣어 주었다
for _ in 0..<K {
    let rectangle = readLine()!.split(separator: " ").map{Int(String($0))!}
    let x1 = rectangle[0], y1 = rectangle[1], x2 = rectangle[2], y2 = rectangle[3]
    
    for i in x1..<x2 {
        for j in y1..<y2 {
            graph[j][i] = 1
        }
    }
}

let dx = [-1, 1, 0, 0]
let dy = [0, 0, -1, 1]

func dfs(_ y: Int, _ x: Int) {
    graph[y][x] = 1
    for i in 0..<4 {
        let nx = x + dx[i]
        let ny = y + dy[i]
        
        if 0..<N ~= nx && 0..<M ~= ny && graph[ny][nx] == 0 {
            graph[ny][nx] = 1
            // 상하좌우 살펴보면서 0인 곳을 발견했다면 count ++
            count += 1
            dfs(ny, nx)
        }
    }
}

for i in 0..<N {
    for j in 0..<M {
        if graph[j][i] == 0 {
            // DFS로 돌 때, 0인 곳을 찾았으면 먼저 count ++
            count += 1
            dfs(j, i)
            regionArray.append(count)
            count = 0
        }
    }
}

print(regionArray.count)
regionArray.sort()
// 문제에서 요구한 출력 형태로 변환
print(regionArray.map{String($0)}.joined(separator: " "))

// 메모리 : 70380 KB, 시간 : 12 ms
