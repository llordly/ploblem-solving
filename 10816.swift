//10816
import Foundation

var n = Int(readLine()!)!
var arrA = readLine()!.split(separator: " ").map(){ Int(String($0))! }
var m = Int(readLine()!)!
let arrB = readLine()!.split(separator: " ").map(){ Int(String($0))! }

var dic = [Int: Int]()
var ans = [Int]()

for i in arrA {
    if dic.keys.contains(i) {
        dic[i]! += 1
    } else {
        dic[i] = 1
    }
}

for i in arrB {
    if dic.keys.contains(i) {
        ans.append(dic[i]!)
    } else {
        ans.append(0)
    }
}
var answer = ""
for i in ans {
    answer += String(i) + " "
}
print(answer)
