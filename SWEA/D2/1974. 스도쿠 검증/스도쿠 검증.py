def checkRow(board):
    for i in range(9):
        if len(set(board[i])) == 9:
            continue
        else:
            return False
    return True

def checkColumn(board):
    for i in range(9):
        sets = set()
        for j in range(9):
            sets.add(board[j][i])
        if len(sets) == 9:
            continue
        else:   return False
    return True

def checkSquare(board):
    sets = set()
    for i in range(3):
        for j in range(3):
            sets = sets | set(board[i*3][j*3:(j+1)*3]) | set(board[i*3+1][j*3:(j+1)*3]) | set(board[i*3+2][j*3:(j+1)*3])
            if len(sets) == 9:
                continue
            else:   return False
    return True

t = int(input())

for i in range(t):
    board = []
    for _ in range(9):
        board.append(list(map(int, input().split())))
    
    if checkRow(board) and checkColumn(board) and checkSquare(board):
        print(f'#{i+1} 1')
    else:   print(f'#{i+1} 0')