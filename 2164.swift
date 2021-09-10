//2164
import Foundation

//let input = readLine()!.split(separator: " ").map(){ Int(String($0))! }

let n = Int(readLine()!)!

var front: Int = 0
var rear: Int = 0
var max_queue_size = 1000002
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

for i in 1...n {
    enqueue(i)
}

while size() > 1 {
    dequeue()
    let temp = dequeue()
    enqueue(temp)
}

print(peek())
