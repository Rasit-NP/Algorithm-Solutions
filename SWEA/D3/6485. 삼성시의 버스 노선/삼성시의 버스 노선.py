t = int(input())

for testcase in range(t):
    n = int(input())
    busRange = []
    for _ in range(n):
        a, b = map(int, input().split())
        busRange.append((a, b))
        
    p = int(input())
    busStop = []
    for _ in range(p):
        c = int(input())
        busStop.append(c)
        
    print(f'#{testcase+1}', end=' ')
    for point in busStop:
        count = 0
        for interval in busRange:
            if interval[0] <= point <= interval[1]:
                count += 1
        print(count, end=' ')
    print()