for tc in range(1, 11):
    n = int(input())
    buildings = list(map(int, input().split()))
    sum_ = 0
    for i in range(2, n-2):
        count = buildings[i] - max(buildings[i-2:i]+buildings[i+1:i+3])
        if count > 0:
            sum_ += count
    
    print(f'#{tc} {sum_}')