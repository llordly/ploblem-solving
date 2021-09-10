//1107
import Foundation

let n = Int(readLine()!)!
let m = Int(readLine()!)!

func remote() {
    if m == 0 {
        let a = String(n).count
        let b = abs(100 - n)
        if a < b { print(a) }
        else { print(b) }
        return
    }
    let input = readLine()!.split(separator: " ").map { Int(String($0))! }
    var button: [Bool] = Array(repeating: false, count: 10)
    for i in input{
        button[i] = true
    }

    var max: Int = -1
    var min: Int = -1

    for i in (0...n).reversed() {
        var temp = i
        var test: Bool = true
        while temp >= 0 {
            if button[temp % 10] {
                test = false
                break
            } else {
                temp /= 10
            }
            if temp == 0 { break }
        }
        if test {
            max = i
            break
        }
    }
    for i in n...1000000 {
        var temp = i
        var test: Bool = true
        while temp >= 0 {
            if button[temp % 10] {
                test = false
                break
            } else {
                temp /= 10
            }
            if temp == 0 { break }
        }
        if test {
            min = i
            break
        }
    }

    if max == -1 {
        max = Int.max
    } else {
        max = n - max + String(max).count
    }

    if min == -1 {
        min = Int.max
    } else {
        min = min - n + String(min).count
    }

    let mid = abs(100 - n)
    print([mid, max, min].min()!)

}
remote()
