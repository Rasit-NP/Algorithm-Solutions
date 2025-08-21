import sys

def input():
    t = int(sys.stdin.readline())
    n = int(sys.stdin.readline())
    a = list(map(int, sys.stdin.readline().split()))
    m = int(sys.stdin.readline())
    b = list(map(int, sys.stdin.readline().split()))
    if n >= m:
        return t, n, a, m, b
    else:
        return t, m, b, n, a

t, n, a, m, b = input()

part_a = []
part_b = []
for i in range(n):
    j = i
    total = a[i]
    part_a.append(total)
    while j < n:
        j += 1
        if j < n:
            total += a[j]
            part_a.append(total)

for i in range(m):
    j = i
    total = b[i]
    part_b.append(total)
    while j < m:
        j += 1
        if j < m:
            total += b[j]
            part_b.append(total)

count = {}
for i in part_b:
    if i in count:
        count[i] += 1
    else:
        count[i] = 1
ans = 0
for i in part_a:
    target = t - i
    if target in count:
        ans += count[target]

print(ans)