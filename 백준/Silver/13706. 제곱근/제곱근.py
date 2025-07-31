import sys

n = int(sys.stdin.readline())

rng = [1, n//2+1]
test = sum(rng)//2

while not test**2 == n:
    if test**2 < n:
        rng[0] = test
    elif test**2 > n:
        rng[1] = test
    test = sum(rng)//2
    

print(test)