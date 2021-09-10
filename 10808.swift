//10808
import Foundation

var alp = [Int](repeating: 0, count: 26)
var ans: String = ""

let s = readLine()!
//97~122

for i in s {
    alp[Int(i.asciiValue!) - 97] += 1
}

for i in 0...25 {
    ans += String(alp[i]) + " "
}
print(ans)
