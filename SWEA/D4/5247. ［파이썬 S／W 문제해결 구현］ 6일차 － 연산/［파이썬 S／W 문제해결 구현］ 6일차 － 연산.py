from collections import deque

t = int(input())
for tc in range(1, t+1):

    n, m = map(int, input().split())
    queue = deque([])
    visited = [None for _ in range(1000001)]
    queue.append(n)
    visited[n] = 0
    while queue:

        x = queue.popleft()
        if x == m:
            ans = visited[x]
            queue.clear()
            break
        elif x-10 >= m:
            nx = x-10
            if 0<nx<=1000000 and visited[nx] is None:
                queue.append(nx)
                visited[nx] = visited[x] + 1
        elif x > m:
            nx = x-1
            if 0<nx<=1000000 and visited[nx] is None:
                queue.append(nx)
                visited[nx] = visited[x] + 1
        else:
            for nx in (x+1, x-1, x*2, x-10):
                if 0<nx<=1000000 and visited[nx] is None:
                    queue.append(nx)
                    visited[nx] = visited[x] + 1
    
    print(f'#{tc}', end=' ')
    print(ans)