import sys

n = int(sys.stdin.readline())

sizes = list(map(int, sys.stdin.readline().split()))

t, p = map(int, sys.stdin.readline().split())

t_sum = 0
for i in range(len(sizes)):
    if sizes[i] % t == 0:
        t_sum += sizes[i]//t
    else:
        t_sum += sizes[i]//t + 1

print(t_sum)
print(f'{n//p} {n%p}')