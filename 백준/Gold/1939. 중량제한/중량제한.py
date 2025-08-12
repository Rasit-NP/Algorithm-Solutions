import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
dic = {}
for i in range(1, n+1):
    dic[i] = []
for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    dic[a].append((b, c))
    dic[b].append((a, c))

ini, fin = map(int, sys.stdin.readline().split())


def test(weight):
    queue = deque([])
    queue.append(ini)
    visited = set()

    while queue:
        now = queue.popleft()
        if now == fin:
            queue.clear()
            return True
        for new, c in dic[now]:
            if new not in visited and weight <= c:
                visited.add(new)
                queue.append(new)
    return False

left = 0
right = 1000000001

while right-left > 1:
    mid = (left+right) // 2
    if test(mid):
        left = mid
    else:
        right = mid

print(left)