//1976
import Foundation

let n = Int(readLine()!)!
let m = Int(readLine()!)!

var parent: [Int] = Array(repeating: -1, count: n + 1)

func find(x: Int) -> Int {
    if parent[x] < 0 {
        return x
    } else {
        let y = find(x: parent[x])
        parent[x] = y
        return y
    }
}

func union(x: Int, y: Int) {
    let x = find(x: x)
    let y = find(x: y)
    
    if x == y { return }
    
    if parent[x] < parent[y] {
        parent[x] += parent[y]
        parent[y] = x
    } else {
        parent[y] += parent[x]
        parent[x] = y
    }
}

for i in 1...n {
    let input = readLine()!.split(separator: " ").map(){ Int(String($0))! }
    for j in 1...n {
        if input[j - 1] == 1 {
            union(x: i, y: j)
        }
    }
}

let sched = readLine()!.split(separator: " ").map(){ Int(String($0))! }

var ans: Bool = true

var temp = find(x: sched[0])
for i in 1...m - 1 {
    let a = find(x: sched[i])
    if temp != a { ans = false }
    temp = a
}

if ans == true { print("YES") }
else { print("NO") }
