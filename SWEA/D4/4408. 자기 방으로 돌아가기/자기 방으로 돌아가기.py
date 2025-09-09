t = int(input())

for tc in range(1, t+1):
    n = int(input())
    std = []
    for _ in range(n):
        a, b = map(int, input().split())
        a, b = min(a-1, b-1), max(a-1, b-1)
        std.append((a//2, b//2))
    
    count = [0 for _ in range(200)]
    for a, b in std:
        for i in range(a, b+1):
            count[i] += 1

    print(f'#{tc}', end=' ')
    print(max(count))