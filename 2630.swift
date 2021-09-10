//2630
import Foundation

let n = Int(readLine()!)!
var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)

var blue: Int = 0
var white: Int = 0

func recur(_ row: Int, _ col: Int, _ n: Int) {
    if n == 1 {
        if arr[row][col] == 0 { white += 1 }
        else { blue += 1 }
        return
    }
    var checkW: Bool = true
    var checkB: Bool = true
    for i in row...row + n-1 {
        for j in col...col + n-1 {
            if arr[i][j] != 0 { checkW = false }
            else { checkB = false }
        }
    }
    if checkB == true { blue += 1 }
    else if checkW == true { white += 1 }
    else {
        let newN: Int = n / 2
        recur(row, col, newN)
        recur(row + newN, col, newN)
        recur(row, col + newN, newN)
        recur(row + newN, col + newN, newN)
    }
}




for i in 0...n-1 {
    let line = readLine()!.split(separator: " ").map(){ Int(String($0))! }
    for j in 0...n-1 {
        arr[i][j] = line[j]
    }
}

recur(0, 0, n)
print(white)
print(blue)
