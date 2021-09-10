//7576
import Foundation

var front: Int = 0
var rear: Int = 0
var max_queue_size = 10000000
var queue: [(Int, Int)] = Array(repeating: (0, 0), count: max_queue_size)

func is_empty() -> Bool {
    return front == rear
}
func enqueue(_ val: (Int, Int)) {
    rear = rear + 1
    queue[rear] = val
}
func dequeue() -> (Int, Int) {
    front = front + 1
    return queue[front]
}

let dx: [Int] = [-1, 1, 0, 0]
let dy: [Int] = [0, 0, -1, 1]


let input = readLine()!.split(separator: " ").map { Int(String($0))! }
let m = input[0]
let n = input[1]

var arr: [[Int]] = Array(repeating: Array(repeating: 0, count: m), count: n)
var dis: [[Int]] = Array(repeating: Array(repeating: 0, count: m), count: n)
var visit: [[Bool]] = Array(repeating: Array(repeating: false, count: m), count: n)


var start: Bool = true

for i in 0..<n {
    let line = readLine()!.split(separator: " ").map { Int(String($0))! }
    for j in 0..<m {
        arr[i][j] = line[j]
        if line[j] == 1 {
            visit[i][j] = true
            enqueue((i, j))
        }
        if line[j] == 0 { start = false }
    }
}

if start { print(0) }
else {
    while !is_empty() {

        let node = dequeue()
        let x = node.0
        let y = node.1
        
       
        visit[x][y] = true

        for k in 0..<4 {
            let nx = x + dx[k]
            let ny = y + dy[k]
            if 0 <= nx && nx < n && 0 <= ny && ny < m {
                if arr[nx][ny] == 0 && !visit[nx][ny] {
                    arr[nx][ny] = 1
                    visit[nx][ny] = true
                    enqueue((nx, ny))
                    dis[nx][ny] = dis[x][y] + 1
                }
            }
        }
    }

    var ans: Bool = true
    var max: Int = 0
    for i in 0..<n {
        for j in 0..<m {
            if arr[i][j] == 0 { ans = false }
            if dis[i][j] > max {
                max = dis[i][j]
            }
        }
    }
    if ans { print(max) }
    else { print(-1) }

}
