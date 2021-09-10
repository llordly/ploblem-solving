//4949
import Foundation

func balance(_ sentence: Array<String>) -> String {
    var stack: [String] = Array<String>()
    for i in sentence {
        if i == "(" || i == "[" {
            stack.append(i)

        }
        if i == ")" || i == "]" {
            var temp: String = ""
            if i == ")" { temp = "(" }
            else { temp = "[" }
            if stack.count == 0 { return "no" }
            if stack.last! == temp {
                stack.removeLast()
            } else {
                return "no"
            }
        }
    }
    if stack.count == 0 {
        return "yes"
    } else {
        return "no"
    }
}


var input = Array(readLine()!).map {String($0)}

while !(input[0] == "." && input.count == 1) {
    print(balance(input))
    input = Array(readLine()!).map {String($0)}
}
