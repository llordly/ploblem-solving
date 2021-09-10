//4195
import Foundation

let test = Int(readLine()!)!

var parent: Dictionary<String, String> = [String: String]()
var rank: Dictionary<String, Int> = [String: Int]()

func find(x: String) -> String {
    if parent[x] == x {
        return x
    } else {
        let y = find(x: parent[x]!)
        parent[x] = y
        return y
    }
}

func union(x: String, y: String) {
    let x = find(x: x)
    let y = find(x: y)
    
    if x == y { return }
    else {
        if rank[x]! > rank[y]! {
            parent[y] = x
            rank[x]! += rank[y]!
        } else {
            parent[x] = y
            rank[y]! += rank[x]!
        }
    }
}

for _ in 1...test {
    let f = Int(readLine()!)!
    parent.removeAll()
    rank.removeAll()
    for _ in 1...f {
        let input = readLine()!.split(separator: " ").map(){ String($0) }
        let a = input[0]
        let b = input[1]
        if !rank.keys.contains(a) {
            parent[a] = a
            rank[a] = 1
        }
        if !rank.keys.contains(b) {
            parent[b] = b
            rank[b] = 1
        }
        union(x: a, y: b)
        print(rank[find(x: a)]!)
    }
}
