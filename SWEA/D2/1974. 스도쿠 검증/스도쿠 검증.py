t = int(input())

for tc in range(1, t+1):

    board = [None] * 9
    for i in range(9):
        board[i] = list(map(int, input().split()))
    
    count_error = 0
    for i in range(9):
        if len(set(board[i])) == 9:
            continue
        else:
            count_error += 1
    
    if count_error > 0:
        print(f'#{tc}', 0)
        continue

    sets = set()
    count_error = 0
    for j in range(9):
        for i in range(9):
            sets.add(board[i][j])
        if len(sets) != 9:
            count_error += 1
        sets.clear()
    
    if count_error > 0:
        print(f'#{tc}', 0)
        continue

    sets = set()
    count_error = 0
    for x in range(0, 9, 3):
        for y in range(0, 9, 3):
            for i in range(3):
                for j in range(3):
                    sets.add(board[x+i][y+j])
            if len(sets) != 9:
                count_error += 1
            sets.clear()
    
    if count_error > 0:
        print(f'#{tc}', 0)
    else:
        print(f'#{tc}', 1)