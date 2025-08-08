t = int(input())

for tc in range(1, t+1):
    n, m = map(int, input().split())

    data = []
    ans = []
    for _ in range(n):
        data.append(list(input()))

    for i in range(n):
        for j in range(n-m+1):
            rkfh = []
            tpfh = []
            for k in range(m):
                if data[i][j+k] == data[i][j+m-(k+1)]:
                    rkfh.append(data[i][j+k])
                else:
                    break
            for k in range(m):
                if data[j+k][i] == data[j+m-(k+1)][i]:
                    tpfh.append(data[j+k][i])
                else:
                    break
            if len(rkfh) == m:
                ans = rkfh
                break
            if len(tpfh) == m:
                ans = tpfh
                break
        if len(ans) > 0:    break


    print(f'#{tc}', end=' ')
    print(''.join(ans))