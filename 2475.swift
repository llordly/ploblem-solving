//2475
import Foundation

let input = readLine()!.components(separatedBy: " ").map({ Int($0)! })

var ans: Int = 0

for i in input {
    ans += i * i
}

print(ans % 10)
