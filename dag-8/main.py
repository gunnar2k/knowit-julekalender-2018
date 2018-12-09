import pandas as pd

input = open("input-dolls.txt")

data = []
for line in input:
    line = line.strip().split(",")
    color = line[0]
    height = int(line[1])
    data.append({'color': color, 'height': height})

df = pd.DataFrame(data)

count = 0
last_color = None
last_height = 0
for row in df.sort_values(by='height').iterrows():
    if row[1]['color'] != last_color and last_height < row[1]['height']:
        last_color = row[1]['color']
        last_height = row[1]['height']
        count += 1
print(count)
