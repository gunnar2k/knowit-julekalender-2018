import matplotlib.pyplot as plt

input = open("input-luke-22.txt")

x = []
y = []
for point in input:
    point = list(map(float, point.strip().split(',')))
    x.append(point[0])
    y.append(point[1])

plt.scatter(x, y, s=0.001)

plt.show()

#
# Oh look a circle!
#
#
# Circumference of circle formula:
#
# 2000*PI = 6283
