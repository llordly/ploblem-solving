//1026
import Foundation

readLine()
var A = readLine()!.components(separatedBy: " ").map({ Int($0)! })
var B = readLine()!.components(separatedBy: " ").map({ Int($0)! })

var min: Int = 0

A.sort()
B.sort(by: >)

for i in 0...A.count - 1 {
    min += A[i] * B[i]
}

print(min)
