import sys

n = int(sys.stdin.readline())
graph = []
save = []
for i in range(1,n+1):
    save.append([0]*i)

for _ in range(n):
    graph.append(list(map(int, sys.stdin.readline().split())))

save[0][0] = graph[0][0]

for i in range(1, n):
    for j in range(len(graph[i])):
        if j == 0:
            save[i][j] = save[i-1][j] + graph[i][j]
        elif j == i:
            save[i][j] = save[i-1][j-1] + graph[i][j]
        else:
            save[i][j] = max(save[i-1][j-1], save[i-1][j])+graph[i][j]

sys.stdout.write(str(max(save[-1])))