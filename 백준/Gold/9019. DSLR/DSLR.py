import sys
from collections import deque

t = int(sys.stdin.readline())

for _ in range(t):
    def D(num):
        return (num*2) % 10000
    def S(num):
        if num == 0:
            return 9999
        else:
            return num-1
    def L(num):
        return (num%1000)*10 + num//1000
    def R(num):
        return num//10 + (num%10)*1000
    
    a, b = map(int, sys.stdin.readline().split())
    queue = deque([])
    visited = set()
    queue.append((a, ''))
    visited.add(a)

    while queue:
        num, route = queue.popleft()
        if num == b:
            ans = route
            queue.clear()
            break
        d = D(num)
        s = S(num)
        l = L(num)
        r = R(num)
        if d not in visited:
            queue.append((d, route+'D'))
            visited.add(d)
        if s not in visited:
            queue.append((s, route+'S'))
            visited.add(s)
        if l not in visited:
            queue.append((l, route+'L'))
            visited.add(l)
        if r not in visited:
            queue.append((r, route+'R'))
            visited.add(r)
    
    print(route)