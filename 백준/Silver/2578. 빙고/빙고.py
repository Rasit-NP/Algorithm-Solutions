import sys

my_board = []
num_list = []
binggo = 0
index = 0
daegak1 = set([(0,0), (1,1), (2,2),(3,3),(4,4)])
daegak2 = set([(0,4), (1,3), (2,2),(3,1),(4,0)])

for _ in range(5):
    my_board.append(list(map(int, sys.stdin.readline().split())))

for _ in range(5):
    num_list += list(map(int, sys.stdin.readline().split()))

while binggo < 3:
    num = num_list[index]

    for i in range(5):
        for j in range(5):
            if my_board[i][j] == num:
                my_board[i][j] = True
                check = (i, j)
    if my_board[check[0]].count(True) == 5:
        binggo += 1
    if [i[check[1]] for i in my_board].count(True) == 5:
        binggo += 1
    if check in daegak1:
        if [my_board[i][i] for i in range(5)].count(True) == 5:
            binggo += 1
    if check in daegak2:
        if [my_board[i][4-i] for i in range(5)].count(True) == 5:
            binggo += 1
    index += 1

print(index)