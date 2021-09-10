//10773
import Foundation
//var R = readLine()!.components(separatedBy: " ").map({ Int($0)! })

var sum: Array<Int> = [Int]()

if let n = Int(readLine()!){
    for _ in 1...n {
        if let input = Int(readLine()!){
            if input == 0 { sum.removeLast() }
            else {
                sum.append(input)
            }
        }
    }
}
var ans: Int = 0

if sum.count == 0 {
    print(0)
} else {
    for i in 0...(sum.count - 1) {
        ans += sum[i]
    }
    print(ans)
}
