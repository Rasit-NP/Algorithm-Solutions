import sys

xtof = list(map(int, sys.stdin.readline().split()))
ftox = [None]*10

for i in range(10):
    ftox[xtof[i]] = i

fa, fb = sys.stdin.readline().rstrip().split()
a = []; b = []

for i in range(len(fa)):
    digit = int(fa[i])
    a.append(ftox[digit])
for i in range(len(fb)):
    digit = int(fb[i])
    b.append(ftox[digit])

apb = int(''.join(map(str, a)))+int(''.join(map(str, b)))
apb = list(map(int, list(str(apb))))
ans = []

for i in range(len(apb)):
    ans.append(xtof[apb[i]])

print(''.join(map(str, ans)))