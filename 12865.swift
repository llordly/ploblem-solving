//12865
import Foundation

let input = readLine()!.split(separator: " ").map(){ Int(String($0))! }

let n = input[0]
let k = input[1]

var w: [Int] = Array<Int>()
var v: [Int] = Array<Int>()
var knapsack: [[Int]] = Array(repeating: Array(repeating: 0, count: k + 1), count: n + 1)

for _ in 0..<n {
    let wv = readLine()!.split(separator: " ").map(){ Int(String($0))! }
    w.append(wv[0])
    v.append(wv[1])
}

for i in 1...n {
    for j in 1...k {
        if w[i - 1] > j {
            knapsack[i][j] = knapsack[i - 1][j]
        } else {
            knapsack[i][j] = [v[i - 1] + knapsack[i - 1][j - w[i - 1]], knapsack[i - 1][j]].max()!
        }
    }
}

print(knapsack[n][k])
