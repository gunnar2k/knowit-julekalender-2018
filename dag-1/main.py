fp = open("input-vekksort.txt", "rb")
sorted = []
for line in fp:
    try:
        current = int(line.strip())
    except ValueError:
        continue
    if len(sorted) == 0:
        sorted.append(current)
    else:
        if current >= sorted[-1]:
            sorted.append(current)
print(sum(sorted))
