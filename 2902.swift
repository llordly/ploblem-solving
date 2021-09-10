//2902
import Foundation

var input = readLine()!.components(separatedBy: "-")

var ans: String = ""
for i in input {
    ans += String(i[i.startIndex])
}
print(ans)
