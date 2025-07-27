import sys
from collections import deque

def bfs(queue):
    a = queue.popleft()
    position = a[0]
    moveCount = a[1]
    for i in range(1,7):
        if position + i > 100:
            break
        elif position + i < 100:
            if position + i not in snakeLadder and position+i not in visited:
                visited.add(position+i)
                queue.append((position+i,moveCount+1))
            elif position + i in snakeLadder and snakeLadder[position+i] not in visited:
                visited.add(snakeLadder[position+i])
                queue.append((snakeLadder[position+i],moveCount+1))
        elif position + i == 100:
            queue.clear()
            print(moveCount + 1)

n, m = map(int, sys.stdin.readline().split())
snakeLadder = {}
visited = set()
visited.add(1)
queue = deque()
queue.append((1,0))

for _ in range(n+m):
    start, end = map(int, sys.stdin.readline().split())
    snakeLadder[start] = end

while queue:
    bfs(queue)