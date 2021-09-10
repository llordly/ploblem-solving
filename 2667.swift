//2667
import Foundation

let dx: [Int] = [-1, 1, 0, 0]
let dy: [Int] = [0, 0, -1, 1]

let n: Int = Int(readLine()!)!
var arr: [[Int]] = Array(repeating: Array<Int>(), count: n)
var visit: [[Bool]] = Array(repeating: Array(repeating: false, count: n), count: n)
var queue = [(Int, Int)]()
var ans = [Int]()



for i in 0..<n {
    arr[i] = Array(readLine()!).map { Int(String($0))! }
}

for i in 0..<n {
    for j in 0..<n {
        if arr[i][j] == 1 && !visit[i][j]{
            var count: Int = 1
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
                    if 0 <= nx && nx < n && 0 <= ny && ny < n {
                        if arr[nx][ny] == 1 && !visit[nx][ny] {
                            visit[nx][ny] = true
                            queue.append((nx, ny))
                            count += 1
                        }
                    }
                }
            }
            ans.append(count)
        }
    }
}

print(ans.count)
ans.sort()
for i in ans {
    print(i)
}
