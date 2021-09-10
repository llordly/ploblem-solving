//11049
import Foundation

let n = Int(readLine()!)!

var dp: [[Int]] = Array(repeating: Array(repeating: 0, count: n + 1), count: n + 1)
var p: [Int] = Array<Int>()

for i in 1...n {
    let input = readLine()!.split(separator: " ").map(){ Int(String($0))! }
    p.append(input[0])
    if i == n { p.append(input[1]) }
}

for d in 0...n - 1 {
    for i in 1...n - d {
        let j: Int = i + d
        if j == i {
            dp[i][j] = 0
            continue
        }
        dp[i][j] = Int.max
        for k in i...j - 1 {
            let min: Int = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j]
            if dp[i][j] > min {
                dp[i][j] = min
            }
        }
    }
}
print(dp[1][n])
