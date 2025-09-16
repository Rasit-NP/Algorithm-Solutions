from itertools import combinations

t = int(input())

for tc in range(1, t+1):

    n = int(input())
    s = [list(map(int, input().split())) for _ in range(n)]
    size = n//2
    minimum = float('inf')
    for com in combinations(range(n), size):
        sum1 = 0
        sum2 = 0
        for i in com:
            for j in com:
                if i < j:
                    sum1 += s[i][j]+s[j][i]
        
        for i in range(n):
            for j in range(i+1, n):
                if i not in com and j not in com:
                    sum2 += s[i][j]+s[j][i]
        minimum = min(minimum, abs(sum1-sum2))
    ans = minimum
    print(f'#{tc}', end=' ')
    print(ans)