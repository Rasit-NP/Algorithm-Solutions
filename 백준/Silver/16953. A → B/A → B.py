import sys, heapq

a, b = map(int, sys.stdin.readline().split())

nums = [(0,a)]

while nums:
    output = heapq.heappop(nums)
    if output[1] * 2 < b:
        heapq.heappush(nums, (output[0]+1, output[1]*2))
    elif output[1] * 2 == b:
        print(output[0]+2)
        break
    if output[1] * 10 + 1 < b:
        heapq.heappush(nums, (output[0]+1, output[1]*10+1))
    elif output[1] * 10 + 1 == b:
        print(output[0]+2)
        break
    if len(nums) == 0:
        print(-1)