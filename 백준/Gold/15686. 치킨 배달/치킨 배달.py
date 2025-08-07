import sys
from itertools import combinations

n, m = map(int, sys.stdin.readline().split())
house = []
chicken = []

for i in range(n):
    inputs = list(map(int, sys.stdin.readline().split()))
    for j in range(n):
        if inputs[j] == 1:
            house.append((i,j))
        elif inputs[j] == 2:
            chicken.append((i,j))
houses = len(house)
chickens = len(chicken)

chicken_dist = [[None]*chickens for _ in range(houses)]

for i in range(houses):
    for j in range(chickens):
        chicken_dist[i][j] = abs(house[i][0]-chicken[j][0]) + abs(house[i][1]-chicken[j][1])


if m == chickens:
    total = 0
    for i in range(houses):
        total += min(chicken_dist[i])
    print(total)
else:
    minimum = float('inf')
    for lst in combinations(range(chickens),m):
        total = 0
        for i in range(houses):
            new_dist = []
            for j in range(chickens):
                if j in lst:
                    new_dist.append(abs(house[i][0]-chicken[j][0]) + abs(house[i][1]-chicken[j][1]))
            total += min(new_dist)

        minimum = min(minimum, total)
    print(minimum)