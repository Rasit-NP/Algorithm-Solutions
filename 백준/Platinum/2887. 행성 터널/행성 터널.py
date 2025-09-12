import sys

def input():

    def dist(planet1, planet2):
        x1, y1, z1 = planet1
        x2, y2, z2 = planet2

        return min(abs(x1-x2), abs(y1-y2), abs(z1-z2))

    n = int(sys.stdin.readline())
    planets = []
    edges = []
    parents = {}
    for _ in range(n):
        x, y, z = map(int, sys.stdin.readline().split())
        planets.append((x, y, z))
        parents[(x, y, z)] = (x, y, z)
    for k in range(3):
        planets.sort(key=lambda x: x[k])
        for i in range(n-1):
            edges.append((dist(planets[i], planets[i+1]), planets[i], planets[i+1]))
    
    edges.sort()

    return n, planets, edges, parents

def find(planet):
    root = planet
    while root != parents[root]:
        parents[root] = parents[parents[root]]
        root = parents[root]
    parents[planet] = root
    return root

n, planets, edges, parents = input()

total = 0

for dist, planet1, planet2 in edges:
    r1 = find(planet1)
    r2 = find(planet2)
    if r1 == r2:
        continue
    else:
        parents[r2] = r1
        total += dist

print(total)