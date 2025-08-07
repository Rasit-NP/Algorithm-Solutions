import sys

def count_color(n, board):
    global total_black
    global total_white
    if n == 2:
        black = sum(board[0])+sum(board[1])
        white = 4 - black
        if black == 4:
            total_black += 1
        elif white == 4:
            total_white += 1
        else:
            total_black += black
            total_white += white
        return black, white
    else:
        dx = [0,0,1,1]
        dy = [0,1,0,1]
        sum_black = 0
        sum_white = 0
        for i in range(4):
            x = dx[i]*(n//2)
            y = dy[i]*(n//2)
            newboard = []
            for j in range(n//2):
                newboard.append(board[x+j][y:y+n//2])
            
            ans = count_color(n//2, newboard)
            sum_black += ans[0]
            sum_white += ans[1]
        if sum_black == n ** 2:
            total_black -= 3
        elif sum_white == n**2:
            total_white -= 3
        return sum_black, sum_white


n = int(sys.stdin.readline())

mainboard = []

for _ in range(n):
    mainboard.append(list(map(int, sys.stdin.readline().split())))
total_black = 0
total_white = 0

ans = count_color(n, mainboard)


print(total_white)
print(total_black)