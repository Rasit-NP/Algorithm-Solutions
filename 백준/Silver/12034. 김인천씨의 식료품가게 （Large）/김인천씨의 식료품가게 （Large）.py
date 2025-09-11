import sys
from collections import deque

t = int(sys.stdin.readline())

for tc in range(1, t+1):
    sys.stdout.write(f'Case #{tc}: ')
    n = int(sys.stdin.readline())
    lst = deque(map(int, sys.stdin.readline().split()))
    ans = []
    
    while lst:
        x = lst.popleft()
        ans.append(x)
        lst.remove((x*4)//3)
    
    sys.stdout.write(' '.join(map(str, ans)))
    sys.stdout.write('\n')