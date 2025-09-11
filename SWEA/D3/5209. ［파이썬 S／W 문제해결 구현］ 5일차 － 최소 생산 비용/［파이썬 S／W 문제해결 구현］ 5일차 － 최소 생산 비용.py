t = int(input())

for tc in range(1, t+1):
    
    n = int(input())
    board = [list(map(int, input().split())) for _ in range(n)]
    print(f'#{tc}', end=' ')
    
    idx = 0
    total = 0
    memo = [None for _ in range(n)]
    sets = set()
    minimum = float('inf')
    state = True
    while idx >= 0:
        if total >= minimum and state:
            idx -= 1
            state = False
            continue
        if idx == n:
            minimum = min(minimum, total)
            idx -= 1
            state = False
            continue
        if memo[idx] is None:
            for i in range(n):
                if i not in sets:
                    memo[idx] = i
                    sets.add(i)
                    total += board[idx][i]
                    idx += 1
                    break
            state = True
        elif memo[idx] < n-1:
            sets.remove(memo[idx])
            total -= board[idx][memo[idx]]
            memo[idx] += 1
            while memo[idx] in sets:
                memo[idx] += 1
            if memo[idx] >= n:
                memo[idx] = None
                idx -= 1
                state = False
                continue
            sets.add(memo[idx])
            total += board[idx][memo[idx]]
            idx += 1
            state = True
        elif memo[idx] == n-1:
            sets.remove(memo[idx])
            total -= board[idx][memo[idx]]
            memo[idx] = None
            idx -= 1
            state = False

    print(minimum)