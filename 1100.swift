//1100

var ans: Int = 0

for i in 0...7 {
    let input = readLine()!
    var index: Int = 0
    for c in input {
        if index % 2 == i % 2 {
            if c == "F" { ans += 1}
        }
        index += 1
    }
}
print(ans)
