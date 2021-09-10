//2178
import Foundation

let dx: [Int] = [-1, 1, 0, 0]
let dy: [Int] = [0, 0, -1, 1]


let input = readLine()!.split(separator: " ").map { Int(String($0))! }
let n = input[0]
let m = input[1]

var arr: [[Int]] = Array(repeating: Array<Int>(), count: n)
var visit: [[Bool]] = Array(repeating: Array(repeating: false, count: m), count: n)
var queue = [(Int, Int, Int)]()

for i in 0..<n {
    arr[i] = Array(readLine()!).map { Int(String($0))! }
}

visit[0][0] = true
queue.append((0, 0, 1))

while !queue.isEmpty {

    let node = queue.removeFirst()
    let x = node.0
    let y = node.1
    let d = node.2
   
    if x == n - 1 && y == m - 1 {
        print(d)
        break
    }
    visit[x][y] = true

    for k in 0..<4 {
        let nx = x + dx[k]
        let ny = y + dy[k]
        if 0 <= nx && nx < n && 0 <= ny && ny < m {
            if arr[nx][ny] == 1 && !visit[nx][ny] {
                visit[nx][ny] = true
                queue.append((nx, ny, d + 1))
            }
        }
    }
}



