import sys, heapq

orders = list(map(int, sys.stdin.readline().split()))

heap = []
heapq.heappush(heap, (0, 0, (0, 0)))
foot_now = {"do": 0, (0, 0): 0}
foot_next = {"do": 1}
while heap:
    time, energy, now_position = heapq.heappop(heap)
    left, right = now_position
    next = orders[time]

    if time > foot_now["do"]:
        foot_now = foot_next
        foot_next = {"do": time+1}

    if next == 0:
        ans = energy
        heap.clear()
        break
    if energy > foot_now[now_position]:
        continue

    ## 왼발이 움질일 때
    if right == next:
        pass
    else:
        if left == next:
            next_energy = energy + 1
        elif left == 0:
            next_energy = energy + 2
        else:
            if abs(next-left) == 2:
                next_energy = energy + 4
            else:
                next_energy = energy + 3
        next_position = (next, right)
        if next_position not in foot_next or (next_position in foot_next and next_energy < foot_next[next_position]):
            foot_next[next_position] = next_energy
            heapq.heappush(heap, (time+1, next_energy, next_position ))
    
    ## 오른발이 움직일 때
    if left == next:
        pass
    else:
        if right == next:
            next_energy = energy + 1
        elif right == 0:
            next_energy = energy + 2
        else:
            if abs(next-right) == 2:
                next_energy = energy + 4
            else:
                next_energy = energy + 3
        next_position = (left, next)
        if next_position not in foot_next or (next_position in foot_next and next_energy < foot_next[next_position]):
            foot_next[next_position] = next_energy
            heapq.heappush(heap, (time+1, next_energy, next_position))

print(ans)