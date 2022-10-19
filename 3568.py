def solve():
    decl = input()
    decl = decl.split(' ', 1)

    var_type = decl[0]
    vars = decl[1][:-1].split(', ')

    for x in vars:
        name = ''
        name_type = ''
        ref = x.find('&')
        arr = x.find('[')
        pointer = x.find('*')
        types = [ref, arr, pointer]
        types.sort()

        type_idx = -1
        for idx in types:
            if idx > -1:
                type_idx = idx
                break
        if type_idx == -1:
            name = x
        else:
            name = x[:type_idx]
            name_type = x[type_idx:][::-1]
            name_type = name_type.replace('][', '[]')


        print(f"{var_type}{name_type} {name};")

solve()