//1012
import Foundation

let dx: [Int] = [-1, 1, 0, 0]
let dy: [Int] = [0, 0, -1, 1]


let t: Int = Int(readLine()!)!
var ans = [Int]()
for _ in 0..<t {
    let input = readLine()!.split(separator: " ").map { Int(String($0))! }
    let m = input[0]
    let n = input[1]
    let k = input[2]
    var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: m), count: n)
    for _ in 0..<k {
        let pos = readLine()!.split(separator: " ").map { Int(String($0))! }
        arr[pos[1]][pos[0]] = 1
    }
    var visit: [[Bool]] = Array(repeating: Array(repeating: false, count: m), count: n)
    var queue = [(Int, Int)]()
    
    var count: Int = 0
    
    for i in 0..<n {
        for j in 0..<m {
            if arr[i][j] == 1 && !visit[i][j]{
                visit[i][j] = true
                queue.append((i, j))
                
                while !queue.isEmpty {

                    let node = queue.removeLast()
                    let x = node.0
                    let y = node.1
                    visit[x][y] = true
                    for k in 0..<4 {
                        let nx = x + dx[k]
                        let ny = y + dy[k]
                        if 0 <= nx && nx < n && 0 <= ny && ny < m {
                            if arr[nx][ny] == 1 && !visit[nx][ny] {
                                visit[nx][ny] = true
                                queue.append((nx, ny))
                            }
                        }
                    }
                }
                count += 1
            }
        }
    }
    print(count)
}
