from itertools import product

count = 0

for prod in product("+-N", repeat=14):
    input = [1,2,3,4,5,6,7,8,7,6,5,4,3,2,1]
    calc = ""
    for idx, value in enumerate(input):
        if idx == 14:
            calc += str(value)
            break
        action = prod[idx].replace("N", "")
        calc += "{}{}".format(value,action)
    total = eval(calc)

    if total == 42:
        count += 1

print(count)
