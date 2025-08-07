t = int(input())

for tc in range(1, t+1):
    n, k = map(int, input().split())
    board = []
    rkfh = []
    count = 0
    tpfh = [[None]*n for _ in range(n)]
    for _ in range(n):
        inputs = input().split()
        board.append(inputs)
        inputs = ''.join(inputs).split('0')
        rkfh.append(inputs)

    for i in range(n):
        for j in range(n):
            tpfh[i][j] = board[j][i]
        tpfh[i] = ''.join(tpfh[i]).split('0')

    for i in range(n):
        for j in rkfh[i]:
            if len(j) == k:
                count += 1
        for j in tpfh[i]:
            if len(j) == k:
                count += 1

    print(f'#{tc}', end=' ')
    print(count)
