import sys, heapq

n = int(sys.stdin.readline())
table = []

for _ in range(n):
    table.append(list(map(int, sys.stdin.readline().split())))

visited = [[float('inf')]*n for _ in range(n)]
visited[0][0] = 0
dx = [1,0]
dy = [0,1]

for i in range(n):
    for j in range(n):
        if i == 0 and 0 < j <= n-1:
            if table[i][j] < table[i][j-1]:
                visited[i][j] = visited[i][j-1]
            else:
                visited[i][j] = visited[i][j-1] + (table[i][j]-table[i][j-1]+1)
        elif j == 0 and 0 < i <= n-1:
            if table[i][j] < table[i-1][j]:
                visited[i][j] = visited[i-1][j]
            else:
                visited[i][j] = visited[i-1][j] + (table[i][j]-table[i-1][j]+1)
        elif i > 0 and j > 0:
            if table[i][j] < table[i][j-1]:
                cost1 = visited[i][j-1]
            else:
                cost1 = visited[i][j-1] + (table[i][j]-table[i][j-1]+1)
            if table[i][j] < table[i-1][j]:
                cost2 = visited[i-1][j]
            else:
                cost2 = visited[i-1][j] + (table[i][j]-table[i-1][j]+1)
            visited[i][j] = min(cost1, cost2)

print(visited[n-1][n-1])