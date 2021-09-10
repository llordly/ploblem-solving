//9184
import Foundation


var input = readLine()!.split(separator: " ").map(){ Int(String($0))! }

var arr: [[[Int]]] = Array(repeating: Array(repeating: Array(repeating: 0, count: 21), count: 21), count: 21)

func w(a: Int, b: Int, c: Int) -> Int {
    if a <= 0 || b <= 0 || c <= 0 {
        return 1
    }
    if a < 21 && b < 21 && c < 21 && arr[a][b][c] != 0 {
        return arr[a][b][c]
    }
    if a > 20 || b > 20 || c > 20 {
        arr[20][20][20] = w(a: 20, b: 20, c: 20)
        return arr[20][20][20]
    }
    if a < b && b < c {
        arr[a][b][c] = w(a: a, b: b, c: c-1) + w(a: a, b: b-1, c: c-1) - w(a: a, b: b-1, c: c)
        return arr[a][b][c]
    }
    arr[a][b][c] = w(a: a-1, b: b, c: c) + w(a: a-1, b: b-1, c: c) + w(a: a-1, b: b, c: c-1) - w(a: a-1, b: b-1, c: c-1)
    return arr[a][b][c]
}

while !(input[0] == -1 && input[1] == -1 && input[2] == -1) {
    print("w(\(input[0]), \(input[1]), \(input[2])) = \(w(a: input[0], b: input[1], c: input[2]))")
    input = readLine()!.split(separator: " ").map(){ Int(String($0))! }
}
