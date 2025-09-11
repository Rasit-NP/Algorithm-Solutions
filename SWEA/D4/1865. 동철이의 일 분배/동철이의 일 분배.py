t = int(input())

for tc in range(1, t+1):
    print(f'#{tc}', end=' ')
    
    n = int(input())

    board = [list(map(int, input().split())) for _ in range(n)]
    largest = 0
    for i in range(n):
        for j in range(n):
            largest = max(largest, board[i][j])
    memo = []
    idx = 0
    maximum = 0
    total = 1
    state = True
    while idx >= 0:
        changed = False
        if idx == n:
            maximum = max(maximum, total)
            idx -= 1
            state = False
            continue
        if state and total * largest**(n-idx) < maximum:
            idx -= 1
            state = False
            continue
        if len(memo) == idx:
            for i in range(n):
                if i not in memo and board[idx][i]:
                    memo.append(i)
                    total *= board[idx][i]
                    idx += 1
                    state = True
                    changed = True
                    break
            if not changed:
                idx -= 1
                state = False
            
        elif memo[idx] < n-1:
            total //= board[idx][memo[idx]]
            for i in range(memo[idx]+1, n):
                if i not in memo and board[idx][i]:
                    memo[idx] = i
                    total *= board[idx][i]
                    idx += 1
                    state = True
                    break
            if state:
                continue
            else:
                memo.pop()
                idx -= 1
                state = False
                continue
        elif memo[idx] == n-1:
            total //= board[idx][memo[idx]]
            memo.pop()
            idx -= 1
            state = False
            continue
    
    maximum /= (100**(n-1))
    ans = round(maximum, 6)
    ans = str(ans).split('.')
    length = len(ans[1])
    if length < 6:
        ans[1] += '0'*(6-length)
    print('.'.join(ans))