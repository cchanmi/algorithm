//
//  boj_15686.swift
//  algorithm
//
//  Created by 황찬미 on 2023/05/04.
//
//  치킨 배달
//  https://www.acmicpc.net/problem/15686

let input = readLine()!.split(separator: " ").map{Int(String($0))!}
let N = input[0]
let M = input[1]
var graph = [[Int]]()

for _ in 0..<N {
    graph.append(readLine()!.split(separator: " ").map{Int(String($0))!})
}

var chickenArray = [(Int, Int)]()
var homeArray = [(Int, Int)]()

for i in 0..<N {
    for j in 0..<N {
        if graph[i][j] == 2 {
            chickenArray.append((i, j))
        } else if graph[i][j] == 1 {
            homeArray.append((i, j))
        }
    }
}

var minValue = Int.max

func findChicken(_ start: Int, _ chickens: [(Int, Int)]) {
    if chickens.count == M {
        minValue = min(minValue, distanceHome(chickens))
    } else {
        for i in start..<chickenArray.count {
            findChicken(i+1, chickens+[chickenArray[i]])
        }
    }
}

func distanceHome(_ chickens: [(Int, Int)]) -> Int {
    var totalDistance = 0
    for home in homeArray {
        var minDistance = Int.max
        for chicken in chickens {
            let distance = abs(home.0-chicken.0)+abs(home.1-chicken.1)
            minDistance = min(minDistance, distance)
        }
        totalDistance += minDistance
    }
    return totalDistance
}

findChicken(0, [])

print(minValue)
