import sys
sys.setrecursionlimit(10**6)

def dfs(start):
    for i in course[start]:
        if visited[i] == False:
            visited[i] = True
            dfs(i)
            course[start] = course[start] | course[i]
        else:
            course[start] = course[start] | course[i]

n = int(sys.stdin.readline())
course = {}
visited = [False] * n
ans = [[0]*n for _ in range(n)]

for i in range(n):
    input = list(map(int, sys.stdin.readline().split()))
    course[i] = set([])
    for j in range(n):
        if input[j] == 1:
            course[i].add(j)

for i in range(n):
    dfs(i)

for i in range(n):
    course[i] = list(course[i])
    for j in course[i]:
        ans[i][j] = 1
    ans[i] = list(map(str, ans[i]))
    sys.stdout.write(' '.join(ans[i]))
    sys.stdout.write('\n')