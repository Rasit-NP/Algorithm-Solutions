import sys

def counting(test_board):
    global total0
    global total1
    global totalm

    if len(test_board) == 3:
        count0 = 0
        count1 = 0
        countm = 0
        for i in range(3):
            for j in range(3):
                if test_board[i][j] == 0:
                    count0 += 1
                elif test_board[i][j] == 1:
                    count1 += 1
                elif test_board[i][j] == -1:
                    countm += 1
        if count0 == 9:
            total0 += 1
        else:
            total0 += count0
        if count1 == 9:
            total1 += 1
        else:
            total1 += count1
        if countm == 9:
            totalm += 1
        else:
            totalm += countm
        return count0, count1, countm
    else:
        length = len(test_board)
        count0 = 0
        count1 = 0
        countm = 0
        for i in range(0, length, length//3):
            for j in range(0, length, length//3):
                new_board = []
                for k in range(length//3):
                    new_board.append(test_board[i+k][j:j+length//3])
                new0, new1, newm = counting(new_board)
                count0 += new0
                count1 += new1
                countm += newm
        if count0 == (length**2) :
            total0 -= 8

        if count1 == (length**2) :
            total1 -= 8

        if countm == (length**2) :
            totalm -= 8

        return count0, count1, countm


n = int(sys.stdin.readline())

board = []

for _ in range(n):
    board.append(list(map(int, sys.stdin.readline().split())))

total0 = 0
total1 = 0
totalm = 0

counting(board)

print(totalm)
print(total0)
print(total1)