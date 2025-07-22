import sys

n = int(sys.stdin.readline())
dic = {i: [] for i in range(1,51)}

for _ in range(n):
    a = sys.stdin.readline().rstrip()
    if dic[len(a)].count(a) == 0:   dic[len(a)].append(a)

for i in range(1, 51):
    dic[i].sort()
    for j in range(len(dic[i])):
        print(dic[i][j])