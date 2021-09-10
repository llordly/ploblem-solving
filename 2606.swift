//2606
import Foundation

let n = Int(readLine()!)!
let edge = Int(readLine()!)!

var adj: [[Int]] = Array(repeating: Array<Int>(), count: n)

var front: Int = 0
var rear: Int = 0
var max_queue_size = 102
var queue: [Int] = Array(repeating: 0, count: max_queue_size)

func is_empty() -> Bool {
    return front == rear
}
func is_full() -> Bool {
    return (rear + 1) == front
}
func size() -> Int {
    return rear - front
}
func enqueue(_ val: Int) {
    rear = rear + 1
    queue[rear] = val
}
func dequeue() -> Int {
    if is_empty() {
        return -1
    }
    front = front + 1
    return queue[front]
}
func peek() -> Int {
    if is_empty() { return -1 }
    return queue[front + 1]
}
func back() -> Int {
    if is_empty() { return -1 }
    return queue[rear]
}

func bfs() -> Int {
    var ans: Int = 0
    var visited: [Bool] = Array(repeating: false, count: n)
    visited[0] = true
    enqueue(0)
    
    while !is_empty() {
        let temp = dequeue()
        for i in adj[temp] {
            if !visited[i] {
                visited[i] = true
                ans += 1
                enqueue(i)
            }
        }
    }
    return ans
}


for _ in 0..<edge {
    let input = readLine()!.split(separator: " ").map(){ Int(String($0))! }
    let i = input[0] - 1
    let j = input[1] - 1
    adj[i].append(j)
    adj[j].append(i)
}
print(bfs())

