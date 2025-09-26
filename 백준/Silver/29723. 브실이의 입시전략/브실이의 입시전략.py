import sys

n, m, k = map(int, sys.stdin.readline().split())

dic = {}
for _ in range(n):
    s, p = sys.stdin.readline().rstrip().split()
    dic[s] = int(p)
base = 0
for _ in range(k):
    subject = sys.stdin.readline().rstrip()
    base += dic.pop(subject)

sort = sorted(dic, key = lambda x: dic[x])
min, max = 0, 0
count = 0
for i in range(m-k):
    min += dic[sort[i]]
    max += dic[sort[-i-1]]

print(base+min, base+max)