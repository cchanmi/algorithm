//
//  boj_2776.swift
//  algorithm
//
//  Created by 황찬미 on 2023/02/17.
//
//  암기왕
//  https://www.acmicpc.net/problem/2776
//
//  입출력 때문에 시간 초과가 난 문제

import Foundation

final class FileIO {
    private let buffer: Data
    private var index: Int = 0
    
    init(fileHandle: FileHandle = FileHandle.standardInput) {
        self.buffer = try! fileHandle.readToEnd()! // 인덱스 범위 넘어가는 것 방지
    }
    
    @inline(__always) private func read() -> UInt8 {
        defer {
            index += 1
        }
        guard index < buffer.count else { return 0 }
        
        return buffer[index]
    }
    
    @inline(__always) func readInt() -> Int {
        var sum = 0
        var now = read()
        var isPositive = true
        
        while now == 10
                || now == 32 { now = read() } // 공백과 줄바꿈 무시
        if now == 45 { isPositive.toggle(); now = read() } // 음수 처리
        while now >= 48, now <= 57 {
            sum = sum * 10 + Int(now-48)
            now = read()
        }
        
        return sum * (isPositive ? 1:-1)
    }


    @inline(__always) func readString() -> String {
            var str = ""
            var now = read()

            while now == 10
                    || now == 32 { now = read() } // 공백과 줄바꿈 무시

            while now != 10
                    && now != 32 && now != 0 {
                str += String(bytes: [now], encoding: .ascii)!
                now = read()
            }

            return str
        }
  }

let file = FileIO()
let testCase = file.readInt()

for _ in 0..<testCase {
    let firstMemo = file.readInt()
    var firstMemoArray = [Int]()
    for _ in 0..<firstMemo {
        firstMemoArray.append(file.readInt())
    }
    firstMemoArray.sort()

    let secondMemo = file.readInt()
    var secondMemoArray = [Int]()
    for _ in 0..<secondMemo {
        secondMemoArray.append(file.readInt())
    }
    
    func binary_search(_ firstMemoArray: [Int], _ value: Int) -> Int {
        var first = 0
        var last = firstMemoArray.count-1
        let returnValue = -1
        while first <= last {
            let mid = (first+last) / 2
            if firstMemoArray[mid] == value {
                return mid
            } else if firstMemoArray[mid] > value {
                last = mid-1
            } else if firstMemoArray[mid] < value {
                first = mid+1
            }
        }
        return returnValue
    }

    for i in secondMemoArray {
        if binary_search(firstMemoArray, i) == -1 { print(0) }
        else { print(1) }
    }
}

// 메모리 : 125692 KB, 시간 : 1800 ms
