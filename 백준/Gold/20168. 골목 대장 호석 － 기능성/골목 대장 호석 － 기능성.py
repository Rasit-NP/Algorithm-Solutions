import sys, heapq

n, m, start, end, money = map(int, sys.stdin.readline().split())
course = {}     #course[star] = [(money1, end1), (money2, end2), ...]

for _ in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    if a not in course:
        course[a] = [(c, b)]
    else:
        course[a].append((c, b))
    if b not in course:
        course[b] = [(c, a)]
    else:
        course[b].append((c, a))

visited = set()
visited.add((0, 0, start))              # (shy, money, position)
heap = []
heapq.heappush(heap,(0,0,start))        # heap[i] = (shy, money, position)

while heap:
    shy, spendMoney, position = heapq.heappop(heap)
    if position == end:
        print(shy)
        heapq.heappush(heap,(1,1,1))
        break
    for nextpoint in course[position]:
        nextmoney = nextpoint[0] + spendMoney
        nextposition = nextpoint[1]
        if (max(shy, nextpoint[0]), nextmoney, nextposition) not in visited and nextmoney <= money:
            visited.add((max(shy, nextpoint[0]), nextmoney, nextposition))
            heapq.heappush(heap, (max(shy, nextpoint[0]), nextmoney, nextposition))

if len(heap) == 0:
    print(-1)