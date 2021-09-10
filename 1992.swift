//1992
import Foundation

let n = Int(readLine()!)!
var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)
var ans: String = ""

var one: Int = 0
var zero: Int = 0

func recur(_ row: Int, _ col: Int, _ n: Int) {
    if n == 1 {
        if arr[row][col] == 0 { ans += "0" }
        else { ans += "1" }
        return
    }
    
    var checkO: Bool = true
    var checkZ: Bool = true
    for i in row...row + n-1 {
        for j in col...col + n-1 {
            if arr[i][j] != 0 { checkZ = false }
            else { checkO = false }
        }
    }
    if checkO == true { ans += "1" }
    else if checkZ == true { ans += "0" }
    else {
        ans += "("
        let newN: Int = n / 2
        recur(row, col, newN)
        recur(row, col + newN, newN)
        recur(row + newN, col, newN)
        recur(row + newN, col + newN, newN)
        ans += ")"
    }
   
}

for i in 0...n-1 {
    let line = Array(readLine()!).map(){ Int(String($0))! }
    for j in 0...n-1 {
        arr[i][j] = line[j]
    }
}

recur(0, 0, n)
print(ans)
