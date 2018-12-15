import re
import operator
fp = open("input-rain.txt", "rb")
slopes = {}
for line in fp:
    coords = map(int, re.findall(r'\d+', line.strip()))
    x1 = float(coords[0])
    y1 = float(coords[1])
    x2 = float(coords[2])
    y2 = float(coords[3])
    slope = (y2 - y1) / (x2 - x1)
    if slope in slopes:
        slopes[slope] += 1
    else:
        slopes[slope] = 1
max = max(slopes.iteritems(), key=operator.itemgetter(1))[0]
print(slopes[max])
