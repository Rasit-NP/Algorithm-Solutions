t = int(input())

for tc in range(1, t+1):
    n, m = map(int, input().split())
    lst = list(map(int, input().split()))

    minimum = float('inf')
    maximum = -float('inf')
    for i in range(n-m+1):
        now = sum(lst[i:i+m])
        minimum = min(minimum, now)
        maximum = max(maximum, now)
    
    print(f'#{tc} {maximum - minimum}')