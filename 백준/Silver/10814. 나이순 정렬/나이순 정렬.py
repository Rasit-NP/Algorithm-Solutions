import sys, heapq

n = int(sys.stdin.readline())

data = []

for i in range(n):
    age, name = sys.stdin.readline().split()
    heapq.heappush(data,(int(age), i, name))




for i in range(n):
    ans = heapq.heappop(data)
    print(ans[0], ans[2])