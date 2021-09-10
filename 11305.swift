//13305
import Foundation

var n = Int(readLine()!)!
var edge = readLine()!.components(separatedBy: " ").map({ Int($0)! })
var node = readLine()!.components(separatedBy: " ").map({ Int($0)! })


var min: Int = node[0]
var index: Int = 0
var sum: Int = 0

for i in 0...edge.count {
    if i == edge.count { break }
    
    if min > node[i] {
        min = node[i]
        index = i
    }
    sum += min * edge[i]
}
print(sum)
