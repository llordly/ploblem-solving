//11758
import Foundation

let p1 = readLine()!.split(separator: " ").map(){ Int(String($0))! }
let p2 = readLine()!.split(separator: " ").map(){ Int(String($0))! }
let p3 = readLine()!.split(separator: " ").map(){ Int(String($0))! }

func ccw(x1: Int, y1: Int, x2: Int, y2: Int, x3: Int, y3: Int) -> Int {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)
}
let ans = ccw(x1: p1[0], y1: p1[1], x2: p2[0], y2: p2[1], x3: p3[0], y3: p3[1])
if ans > 0 {
    print(1)
} else if ans == 0 {
    print(0)
} else {
    print(-1)
}
