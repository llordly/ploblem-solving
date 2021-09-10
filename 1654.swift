//1654
import Foundation

let input = readLine()!.split(separator: " ").map() { Int(String($0))! }
let k = input[0]
let n = input[1]
var max: Int = 0

var arr: [Int] = Array<Int>()

for _ in 0..<k {
    let temp = Int(readLine()!)!
    if temp > max {
        max = temp
    }
    arr.append(temp)
}


func paramSearch() -> Int {
    var start: Int = 1
    var end: Int = max
    var mid: Int = (start + end) / 2
    while (end - start) >= 0 {
        var sum: Int = 0
        for i in arr {
            sum += i / mid
        }
        if sum >= n {
            start = mid + 1
        } else {
            end = mid - 1
        }
        mid = (end + start) / 2
    }
    return mid
}

print(paramSearch())
