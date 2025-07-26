import sys

n = int(sys.stdin.readline())
data = []
rank = []

for i in range(n):
    data.append(tuple(map(int, sys.stdin.readline().split())))

for i in range(n):
    count = 1
    for j in range(n):
        if i != j:
            if data[j][1] > data[i][1] and data[j][0] > data[i][0]:
                count += 1
    rank.append(count)

sys.stdout.write(" ".join(list(map(str, rank))))