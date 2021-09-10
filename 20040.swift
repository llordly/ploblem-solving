//20040
import Foundation

let input = readLine()!.split(separator: " ").map(){ Int(String($0))! }
let n = input[0]
let m = input[1]

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

func union(x: Int, y: Int) -> Int {
    let x = find(x: x)
    let y = find(x: y)
    
    if x == y { return cnt }
    if parent[x] < parent[y] {
        parent[x] += parent[y]
        parent[y] = x
    } else {
        parent[y] += parent[x]
        parent[x] = y
    }
    cnt += 1
    return 0
}

var cnt: Int = 1
var ans: Bool = true
for _ in 1...m {
    let cycle = readLine()!.split(separator: " ").map(){ Int(String($0))! }
    if union(x: cycle[0], y: cycle[1]) != 0 {
        ans = false
        print(cnt)
        break;
    }
}
if ans { print(0) }


