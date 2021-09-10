//1780
import Foundation

let n = Int(readLine()!)!
var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)

var minus: Int = 0
var zero: Int = 0
var plus: Int = 0

func recur(_ row: Int, _ col: Int, _ n: Int) {
    if n == 1 {
        if arr[row][col] == 0 { zero += 1 }
        else if arr[row][col] == 1 { plus += 1 }
        else { minus += 1 }
        return
    }
    var checkPlus: Bool = true
    var checkMinus: Bool = true
    var checkZero: Bool = true
    for i in row...row + n-1 {
        for j in col...col + n-1 {
            if arr[i][j] != 0 { checkZero = false }
            if arr[i][j] != 1 { checkPlus = false }
            if arr[i][j] != -1 { checkMinus = false }
        }
    }
    if checkPlus == true { plus += 1 }
    else if checkMinus == true { minus += 1 }
    else if checkZero == true { zero += 1 }
    else {
        let newN: Int = n / 3
        for i in 0..<n where i % newN == 0 {
            for j in  0..<n where j % newN == 0 {
                recur(row + i, col + j, newN)
            }
        }
    }
}

for i in 0...n-1 {
    let line = readLine()!.split(separator: " ").map(){ Int(String($0))! }
    for j in 0...n-1 {
        arr[i][j] = line[j]
    }
}

recur(0, 0, n)
print(minus)
print(zero)
print(plus)
