t = int(input())

for tc in range(1, t+1):
    n = int(input())

    board = []
    for _ in range(n):
        board.append(list(map(int, input().split())))
    
    sets = set()
    total = 0
    minimum = float('inf')
    def backtracking(lst):
        global total
        global minimum
        if len(lst) == n:
            minimum = min(minimum, total)
        else:
            for i in range(n):
                if i not in sets:
                    total += board[len(lst)][i]
                    lst.append(i)
                    sets.add(i)
                    if total < minimum:
                        backtracking(lst)
                    sets.remove(i)
                    lst.pop()
                    total -= board[len(lst)][i]
    backtracking([])
    print(f'#{tc}', end=' ')
    print(minimum)