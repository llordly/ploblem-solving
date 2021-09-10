//1027
import Foundation

var n = readLine()
var input = readLine()!.components(separatedBy: " ").map({ Int($0)! })
var max: Int = 0

func ccw(x1: Int, y1: Int, x2: Int, y2: Int, x3: Int, y3: Int) -> Int {
    return (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)
}

for i in 0...input.count - 1 {
    var cnt = 0
    for j in 0...i{
        if i == j { continue }
        var check: Bool = true
        for k in j...i {
            if k == j || k == i { continue }
            if ccw(x1: j, y1: input[j], x2: k, y2: input[k], x3: i, y3: input[i]) <= 0 {
                check = false
            }
        }
        if check { cnt += 1 }
    }
    for j in i...input.count - 1 {
        if i == j { continue }
        var check: Bool = true
        for k in i...j {
            if k == j || k == i { continue }
            if ccw(x1: i, y1: input[i], x2: k, y2: input[k], x3: j, y3: input[j]) <= 0 {
                check = false
            }
        }
        if check { cnt += 1 }
    }
    if cnt >= max {
        max = cnt
    }
//    print(cnt)
}

print(max)
