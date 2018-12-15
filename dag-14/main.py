import numpy as np
import decimal

np.set_printoptions(threshold=np.inf)

input = open("input-bounding-crisscross.txt").read().strip()

moves = [input[i:i+2] for i in range(0, len(input), 2)]

x = 0
y = 0
min_x = x
min_y = y
max_x = x
max_y = y

for move in moves:
    distance = int(move[0:-1])
    direction = move[-1]
    if direction == "V":
        x -= distance
    elif direction == "F":
        y += distance
    elif direction == "H":
        x += distance
    elif direction == "B":
        y -= distance

    min_x = min(x, min_x)
    max_x = max(x, max_x)
    min_y = min(y, min_y)
    max_y = max(y, max_y)

area = np.zeros([max_x - min_x + 1, max_y - min_y + 1])

x = abs(min_x)
y = abs(min_y)

for move in moves:
    distance = int(move[0:-1])
    direction = move[-1]
    if direction == "V":
        area[x-distance:x,y] = 1
        x -= distance
    elif direction == "F":
        area[x,y:y+distance+1] = 1
        y += distance
    elif direction == "H":
        area[x:x+distance+1,y] = 1
        x += distance
    elif direction == "B":
        area[x,y-distance:y] = 1
        y -= distance


flattened = area.flatten()
num_zeros = (flattened == 0).sum()
num_ones = (flattened == 1).sum()

for row in area:
    print("".join(map(str, map(int, row))))

answer = decimal.Decimal(float(num_ones)/num_zeros)
print(answer)
