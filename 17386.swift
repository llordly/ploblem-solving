//17386
import Foundation

let l1 = readLine()!.split(separator: " ").map(){ Int(String($0))! }
let l2 = readLine()!.split(separator: " ").map(){ Int(String($0))! }


func ccw(x1: Int, y1: Int, x2: Int, y2: Int, x3: Int, y3: Int) -> Int {
    var temp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)
    if temp > 0 { return 1 }
    else if  temp == 0 { return 0 }
    else { return -1 }
}

let abc = ccw(x1: l1[0], y1: l1[1], x2: l1[2], y2: l1[3], x3: l2[0], y3: l2[1])
let abd = ccw(x1: l1[0], y1: l1[1], x2: l1[2], y2: l1[3], x3: l2[2], y3: l2[3])
let cda = ccw(x1: l2[0], y1: l2[1], x2: l2[2], y2: l2[3], x3: l1[0], y3: l1[1])
let cdb = ccw(x1: l2[0], y1: l2[1], x2: l2[2], y2: l2[3], x3: l1[2], y3: l1[3])


if abc * abd < 0 && cda * cdb < 0 {
    print(1)
} else {
    print(0)
}
