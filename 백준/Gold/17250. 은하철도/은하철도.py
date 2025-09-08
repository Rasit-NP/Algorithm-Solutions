import sys

def input():
    n, m = map(int, sys.stdin.readline().split())
    planets = [None for _ in range(n+1)]
    parents = [i for i in range(n+1)]
    for i in range(1, n+1):
        planets[i] = int(sys.stdin.readline())
    return n, m, planets, parents

def find(x):
    root = x
    while root != parents[root]:
        root = parents[root]
    return root

n, m, planets, parents = input()

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split())
    ra = find(a)
    rb = find(b)
    if ra != rb:
        parents[rb] = ra
        planets[ra] += planets[rb]
    sys.stdout.write(str(planets[ra]) + '\n')