import io
message = io.open("input.txt", encoding="utf-8") \
    .read() \
    .strip() \
    .encode('unicode-escape')
codes = [message[x:x+10] for x in range(0,len(message),10)]
answer = []
for code in codes:
    offset = int("0x{}".format(code[-2:]),0)
    answer.append(chr(32 + offset))
print("".join(answer))
