letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZÆØÅ"
words = "GODJULOGGODTNYTTÅR"

answer = 0
for i, char in enumerate(reversed(words)):
    answer += (letters.find(char)+1) * 29**i

print(answer)
