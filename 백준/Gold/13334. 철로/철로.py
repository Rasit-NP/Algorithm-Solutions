import sys, heapq

def init(n):
    global positions, startend, length
    positions = []
    startend = set()
    for _ in range(n):
        h, o = map(int, sys.stdin.readline().split())
        positions.append((min(h, o), max(h, o)))
        startend.add(h)
        startend.add(o)
    length = int(sys.stdin.readline())
    heapq.heapify(positions)
    startend = list(startend)
    startend.sort()

def run():
    waiting = []
    content = []
    maximum = 0
    cnt = 0
    for head in startend:
        tail = head + length
        while positions and positions[0][0] <= tail:
            h, o = heapq.heappop(positions)
            heapq.heappush(waiting, (o, h))
        while waiting and waiting[0][0] <= tail:
            o, h = heapq.heappop(waiting)
            heapq.heappush(content, h)
            cnt += 1
        while content and content[0] < head:
            heapq.heappop(content)
            cnt -= 1
        maximum = max(maximum, cnt)
        head += 1
        tail += 1
    print(maximum)

if __name__ == '__main__':
    n = int(sys.stdin.readline())
    init(n)
    run()