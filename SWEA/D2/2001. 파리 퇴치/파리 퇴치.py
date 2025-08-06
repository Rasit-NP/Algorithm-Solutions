t = int(input())

for tc in range(1, t+1):
    n, m = map(int, input().split())

    board = [None]*n
    for i in range(n):
        board[i] = list(map(int, input().split()))


    maximum = 0
    for i in range(n-(m-1)):
        for j in range(n-(m-1)):
            sum = 0
            for ni in range(i, i+m):
                for nj in range(j, j+m):
                    sum += board[ni][nj]
            maximum = max(sum, maximum)
    
    print(f'#{tc}', maximum)