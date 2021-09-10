//1074
import Foundation

let input = readLine()!.split(separator: " ").map { Int(String($0))! }
let n = input[0]
let r = input[1]
let c = input[2]

var N: Int = 1
for _ in 1...n {
    N *= 2
}


var count: Int = 0

func recur(_ row: Int, _ col: Int, _ n: Int) {
    if n == 1 {
        count += 1
        if row == r && col == c {
            print(count - 1)
            return
        }
    }
    else {
        let newN: Int = n / 2
        let pow = newN * newN
        if r < row + newN {
            if c < col + newN {
                recur(row, col, newN)
            } else {
                count += pow
                recur(row, col + newN, newN)
            }
        } else {
            count += 2 * pow
            if c < col + newN {
                recur(row + newN, col, newN)
            } else {
                count += pow
                recur(row + newN, col + newN, newN)
            }
        }
    }
}
recur(0, 0, N)
