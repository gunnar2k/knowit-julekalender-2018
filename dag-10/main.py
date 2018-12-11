import math
input = open("input.spp")
stack = []
for line in input:
    cmds = line.rstrip()
    for cmd in cmds:
        if cmd == " ":
            stack.append(31)
        elif cmd == ":":
            stack = [sum(stack)]
        elif cmd == "|":
            stack.append(3)
        elif cmd == "'":
            pop1 = stack.pop()
            pop2 = stack.pop()
            stack.append(sum([pop1,pop2]))
        elif cmd == ".":
            A = stack.pop()
            B = stack.pop()
            stack.append(A-B)
            stack.append(B-A)
        elif cmd == "_":
            A = stack.pop()
            B = stack.pop()
            stack.append(A*B)
            stack.append(A)
        elif cmd == "/":
            stack.pop()
        elif cmd == "i":
            stack.append(stack[-1])
        elif cmd == "\\":
            stack[-1] += 1
        elif cmd == "*":
            A = stack.pop()
            B = stack.pop()
            calc = float(A) / float(B)
            result = math.floor(calc)
            if calc < 0:
                result = math.ceil(calc)
            result = int(result)
            stack.append(result)
        elif cmd == "]":
            value = stack.pop()
            if value % 2 == 0:
                stack.append(1)
        elif cmd == "[":
            value = stack.pop()
            if value % 2 != 0:
                stack.append(value)
        elif cmd == "~":
            val1 = stack.pop()
            val2 = stack.pop()
            val3 = stack.pop()
            stack.append(max(val1,val2,val3))
        elif cmd == "K":
            break
print(max(stack))
