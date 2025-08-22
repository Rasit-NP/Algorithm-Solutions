import sys

def input():
    n = int(sys.stdin.readline())
    lst = list(map(int, sys.stdin.readline().split()))

    return n, lst

n, a = input()

tail = []

for i in range(n):
    now = a[i]
    length = len(tail)
    if not tail:
        tail.append(now)
    else:
        if now <= tail[-1]:
            left = -1
            right = length-1
            while right - left > 1:
                test = (left + right)//2
                if tail[test] >= now:
                    right = test
                else:
                    left = test
            tail[right] = now
        else:
            tail.append(now)

print(len(tail))