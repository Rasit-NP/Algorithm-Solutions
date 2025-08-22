import sys
from collections import deque

t = int(sys.stdin.readline())
ans = []

for _ in range(t):
    def input():
        n = int(sys.stdin.readline())
        arrow = [None] + list(map(int, sys.stdin.readline().split()))
        inner = [0] * (n+1)
        for i in range(1, n+1):
            inner[arrow[i]] += 1

        return n, arrow, inner

    n, arrow, inner = input()
    queue = deque([])

    for i in range(1, n+1):
        if inner[i] == 0:
            queue.append(i)
    
    count = 0

    while queue:
        a = queue.popleft()
        count += 1
        love = arrow[a]
        inner[love] -= 1
        if inner[love] == 0:
            queue.append((love))
    
    ans.append(str(count))

print('\n'.join(ans))