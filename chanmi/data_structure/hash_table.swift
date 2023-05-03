//
//  hash_table.swift
//  algorithm
//
//  Created by 황찬미 on 2023/05/02.
//

var hashTable: [String?] = Array(repeating: nil, count: 3)

func hash(key: Int) -> Int {
    return key % 3
}

func updateValue(key: String, value: String) {
    guard let key = UnicodeScalar(key)?.value else { return }
    let hashIndex = hash(key: Int(key))
    hashTable[hashIndex] = value
}

func getValue(key: String) -> String? {
    guard let key = UnicodeScalar(key)?.value else { return nil }
    let hashIndex = hash(key: Int(key))
    return hashTable[hashIndex]
}

func removeValue(key: String) {
    guard let key = UnicodeScalar(key)?.value else { return }
    let hashIndex = hash(key: Int(key))
    hashTable[hashIndex] = nil
}

// 충돌값 없는 상태
updateValue(key: "황", value: "짠미")
updateValue(key: "개", value: "미미")
updateValue(key: "유", value: "서린")

// 짠미, 미미, 서린
print(getValue(key: "황")!)
print(getValue(key: "개")!)
print(getValue(key: "유")!)

// [Optional("서린"), Optional("짠미"), Optional("미미")]
print(hashTable)

// 충돌 발생
updateValue(key: "황", value: "짠미")
updateValue(key: "백", value: "준")
updateValue(key: "유", value: "서린")

// 짠미, 서린, 서린
print(getValue(key: "황")!)
print(getValue(key: "백")!)
print(getValue(key: "유")!)

