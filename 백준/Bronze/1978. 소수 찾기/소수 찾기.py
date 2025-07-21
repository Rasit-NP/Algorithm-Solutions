import math
T = int(input())

def checkPrime(n):
    for i in listPrime:
        if n%i == 0:
            return False
    return True

nums = set(list(map(int, input().split())))
maximum = max(nums)
listPrime = [2, 3]

for i in range(4, maximum+1):
    if checkPrime(i):
        listPrime.append(i)

listPrime = set(listPrime)

print(len(list(nums & listPrime)))