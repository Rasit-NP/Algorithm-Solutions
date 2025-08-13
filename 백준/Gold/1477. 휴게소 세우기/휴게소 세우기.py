import sys

n, m, l = map(int, sys.stdin.readline().split())

def func(num):
    count = 0
    for i in range(n+1):
        count += (relax[i+1]-relax[i]-1)//num
    return count


if n == 0:
    relax = [0, l]
else:
    relax = [0] + sorted(list(map(int, sys.stdin.readline().split()))) + [l]

left = 0
right = l

while right-left>1:
    test = (left+right)//2
    check = func(test)
    if check > m:
        left = test
    else:
        right = test

print(right)