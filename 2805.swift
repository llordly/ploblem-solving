//2805
import Foundation

let input = readLine()!.split(separator: " ").map() { Int(String($0))! }
let n = input[0]
let m = input[1]

var arr = readLine()!.split(separator: " ").map() { Int(String($0))! }
let max = arr.max()!

func paramSearch() -> Int {
    var start: Int = 1
    var end: Int = max
    var mid: Int = (start + end) / 2
    while (end - start) >= 0 {
        var sum: Int = 0
        for i in arr {
            let temp: Int = i - mid
            if temp >= 0 {
                sum += temp
            }
        }
        if sum >= m {
            start = mid + 1
        } else {
            end = mid - 1
        }
        mid = (end + start) / 2
    }
    return mid
}

print(paramSearch())
