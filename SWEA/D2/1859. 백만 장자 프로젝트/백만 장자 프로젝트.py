t = int(input())

for tc in range(1, t+1):
    n = int(input())
    lst = list(map(int, input().split()))

    large = 0
    total = 0
    for i in range(n-1, -1, -1):
        if lst[i] > large:
            large = lst[i]
        else:
            total += large-lst[i]
    
    print(f'#{tc}', end = ' ')
    print(total)