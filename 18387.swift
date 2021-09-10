//17387
import Foundation

var l1 = readLine()!.split(separator: " ").map(){ Int(String($0))! }
var l2 = readLine()!.split(separator: " ").map(){ Int(String($0))! }


func ccw(x1: Int, y1: Int, x2: Int, y2: Int, x3: Int, y3: Int) -> Int {
    let temp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)
    if temp > 0 { return 1 }
    else if  temp == 0 { return 0 }
    else { return -1 }
}

let abc = ccw(x1: l1[0], y1: l1[1], x2: l1[2], y2: l1[3], x3: l2[0], y3: l2[1])
let abd = ccw(x1: l1[0], y1: l1[1], x2: l1[2], y2: l1[3], x3: l2[2], y3: l2[3])
let cda = ccw(x1: l2[0], y1: l2[1], x2: l2[2], y2: l2[3], x3: l1[0], y3: l1[1])
let cdb = ccw(x1: l2[0], y1: l2[1], x2: l2[2], y2: l2[3], x3: l1[2], y3: l1[3])

let ab = abc * abd
let cd = cda * cdb

func bigger(x1: Int, x2:Int, y1: Int, y2: Int) -> Bool {
    if x1 == x2 {
        return y1 >= y2
    }
    return x1 >= x2
}

func sol() -> Bool {
    if ab == 0 && cd == 0 {
        if bigger(x1:l1[0], x2:l1[2], y1:l1[1], y2:l1[3]) {
            l1.swapAt(0, 2)
            l1.swapAt(1, 3)
        }
        if bigger(x1:l2[0], x2:l2[2], y1:l2[1], y2:l2[3]) {
            l2.swapAt(0, 2)
            l2.swapAt(1, 3)
        }
        return bigger(x1:l1[2], x2:l2[0], y1:l1[3], y2:l2[1]) && bigger(x1:l2[2], x2:l1[0], y1:l2[3], y2:l1[1])
    }
    return ab <= 0 && cd <= 0
}

if sol() {
    print(1)
} else {
    print(0)
}
