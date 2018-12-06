answer = 0
for x in range(1, 18163106):
    if x % 100000 == 0:
        print(x)
    digits = [int(d) for d in str(x)]
    zeros = digits.count(0)
    non_zeros = len(digits) - zeros
    if zeros > non_zeros:
        answer += x
print(answer)
