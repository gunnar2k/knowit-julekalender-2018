'''
Helper functions for prime numbers
'''

from math import sqrt
from itertools import count, islice

def is_prime(n):
    return n > 1 and all(n%i for i in islice(count(2), int(sqrt(n)-1)))

def sum_of_primes(arr):
    primes = filter(is_prime, arr)
    return sum(primes)


'''
Solution
'''

from itertools import combinations

N = [1,3]
last_N = 3
current_N = None
prime_count = 1

def is_distinct(n, N):
    count = 0
    for i in combinations(N,2):
        if n == i[0] + i[1]:
            count += 1
            if count > 1:
                break
    if count == 1:
        return True
    else:
        return False

while prime_count < 100:
    current_N = last_N + 1

    if is_distinct(current_N, N):
        N.append(current_N)

        if is_prime(current_N):
            print "New prime count:", prime_count
            prime_count += 1

    last_N = current_N


answer = sum_of_primes(N)

print(answer)
