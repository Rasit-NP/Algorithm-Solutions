import sys

def bellman_ford(n, start, edges, money):

    visited = [-float('inf')] * (n+1)
    visited[start] = money

    for _ in range(n):
        for s, e, c in edges:
            if visited[s] != -float('inf') and visited[e] < visited[s] + c and visited[s]+c >= 0:
                visited[e] = visited[s] + c

    for s, e, c in edges:
        if visited[e] < visited[s] + c and visited[s] + c >= 0:
            return False

    return True


n, m = map(int, sys.stdin.readline().split())
trades = []

# 입력
for _ in range(m):
    inputs = list(map(int, sys.stdin.readline().split()))
    case = inputs[0]
    if case == 1:
        s, e, c = 0, inputs[2], -inputs[1]
    elif case == 2:
        s, e, c = inputs[1], 0, inputs[2]
    elif case == 3:
        s, e, c = inputs[1], inputs[2], 0
    elif case == 4:
        s, e, c = inputs[1], inputs[3], -inputs[2]
    elif case == 5:
        s, e, c = inputs[1], inputs[2], inputs[3]
    trades.append((s, e, c))

left = 0
right = min(n**2+n, 3000) * 1000 + 1

if bellman_ford(n, 0, trades, right):
    print('INF')

else:
    while right-left > 1:
        test = (left+right)//2
        if bellman_ford(n, 0, trades, test):
            left = test
        else:
            right = test
    print(right)