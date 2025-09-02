import sys

a, b = sys.stdin.readline().rstrip().split()
if len(a) > len(b):
    a, b = b, a
a, b = list(a), list(b)
len_a, len_b = len(a), len(b)

d = len_b - len_a
ans = []
for i in range(d):
    ans.append(b[i])
for i in range(len_a):
    ans.append(str(int(a[i])+int(b[d+i])))

print(''.join(ans))