import sys

def bellman_ford(n, start, edges):      ## (노드 수, 출발지점, 그래프)
    dist = [float('inf')]*(n+1)
    dist[start] = 0
    
    for _ in range(n-1):
        for ini, fin, distance in edges:
            if dist[fin] > dist[ini] + distance:
                dist[fin] = dist[ini] + distance
    
    for ini, fin, distance in edges:
        if dist[fin] > dist[ini] + distance:
            return False
        
    return dist[1:]

n, m = map(int, sys.stdin.readline().split())
edges = []



for _ in range(m):
    edges.append(tuple(map(int, sys.stdin.readline().split())))

ans = bellman_ford(n, 1, edges)

if ans == False:
    print(-1)
else:
    for i in range(len(ans)):
        if i != 0:
            if ans[i] != float('inf'):
                print(ans[i])
            else:
                print(-1)