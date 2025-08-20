t = int(input())

for tc in range(1, t+1):
    n, m = map(int, input().split())

    lst = list(map(int, input().split()))
    ans = lst[m%n]

    print(f'#{tc}', end=' ')
    print(ans)