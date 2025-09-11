t = int(input())

for tc in range(1, t+1):
    print(f'#{tc}', end=' ')

    n, b = map(int, input().split())
    lst = list(map(int, input().split()))
    minimum = float('inf')

    for i in range(1<<n):
        total = 0
        for k in range(n):
            digit = 1<<k
            if i & digit:
                total += lst[k]
                if total >= minimum:
                    break
        if total > b:
            minimum = min(minimum, total)
        elif total == b:
            minimum = b
            break
    
    print(minimum - b)