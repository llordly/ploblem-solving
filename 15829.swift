//15829
import Foundation

let r: Int = 31
let M: Int = 1234567891

let l: Int = Int(readLine()!)!
let input = Array(readLine()!).map {String($0)}
var sum: Int = 0

for i in 0..<l {
    var temp: Int = Int(Character(input[i]).unicodeScalars.first!.value - 96)
    if i != 0 {
        for _ in 1...i {
            temp = temp * r
            temp %= M
        }
    }
    sum += temp
    sum %= M
}
print(sum)
