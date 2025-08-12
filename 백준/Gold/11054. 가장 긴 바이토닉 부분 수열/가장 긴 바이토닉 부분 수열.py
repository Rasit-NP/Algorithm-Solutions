import sys

n = int(sys.stdin.readline())

lst = list(map(int, sys.stdin.readline().split()))

asc = [1] * n
desc = [1] * n

for i in range(n):
    for j in range(i+1, n):
        if lst[j] > lst[i]:
            asc[j] = max(asc[i]+1, asc[j])

for i in range(n-1, -1, -1):
    for j in range(i):
        if lst[j] > lst[i]:
            desc[j] = max(desc[i]+1, desc[j])

maximum = 0
for i in range(n):
    total = asc[i] + desc[i] - 1
    maximum = max(maximum, total)

print(maximum)