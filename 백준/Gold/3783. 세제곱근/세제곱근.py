import sys, math

t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())

    n = n * (10**30)
    left = 0
    right = int(math.sqrt(n))+1

    while right-left > 1:
        mid = (left+right)//2
        cube = mid**3
        if cube < n:
            left = mid
        elif cube > n:
            right = mid
        else:
            left = mid
            break
    ans_int = left // (10**10)
    ans_float = str(left)[-10:]


    print(f'{ans_int}.{ans_float}')