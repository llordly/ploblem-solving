//1920
import Foundation

var n = Int(readLine()!)!
var arrA = readLine()!.components(separatedBy: " ").map({ Int($0)! })
var m = Int(readLine()!)!
let arrB = readLine()!.components(separatedBy: " ").map({ Int($0)! })

arrA.sort()

func binarySearch(num: Int) -> Int {
    var start: Int = 0
    var end: Int = arrA.count - 1
    var mid: Int = (start + end) / 2
    while (end - start) >= 0 {
        if (arrA[mid] == num) {
            return 1
        } else if (arrA[mid] <= num) {
            start = mid + 1
        } else {
            end = mid - 1
        }
        mid = (end + start) / 2
    }
    return 0
}

for x in arrB {
    print(binarySearch(num: x))
}
