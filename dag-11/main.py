input = open("input-crisscross.txt") \
    .read() \
    .strip()
x,y = 0,0
i = 0
while i < len(input):
    action = input[i:i+2]
    distance = int(action[0:-1])
    direction = action[-1]
    if direction == "F":
        y += distance
    elif direction == "H":
        x += distance
    elif direction == "V":
        x -= distance
    elif direction == "B":
        y -= distance
    i += 2
print("[{},{}]".format(x,y))
