t = int(input())

for tc in range(1, t+1):
    n = int(input())
    lst = list(map(int, input().split()))
    
    print(f'#{tc} {max(lst)-min(lst)}')