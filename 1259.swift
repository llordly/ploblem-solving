//1259
import Foundation

var input = readLine()!

while input != "0" {
    var arr = input.map { String($0) }
    if arr == arr.reversed() { print("yes") }
    else { print("no") }
    input = readLine()!
}
