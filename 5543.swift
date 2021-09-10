//5543
import Foundation

//let input = readLine()!.components(separatedBy: " ").map({ Int($0)! })

var minH: Int = 3000
var minB: Int = 3000


for i in 1...5 {
    if let set = Int(readLine()!) {
        if i <= 3 {
            if minH >= set {
                minH = set
            }
        } else {
            if minB >= set {
                minB = set
            }
        }
    }
}

print(minH + minB - 50)
