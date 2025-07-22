from collections import deque
import math

def bfs(queue, target):
    num = queue.popleft()
    for i in range(1, int(math.sqrt(num))+1):
        newN = num + i**2
        if newN > target:
            break
        elif newN == target:
            queue = deque([newN])
            dic[newN] = dic[num] + 1
            break
        elif newN not in dic:
            queue.append(newN)
            dic[newN] = dic[num] + 1


n = int(input())
queue = deque([])
dic = {}

for i in range(1, int(math.sqrt(n))+1):
    dic[i**2] = 1
    queue.append(i**2)

while n not in dic:
    bfs(queue,n)

print(dic[n])