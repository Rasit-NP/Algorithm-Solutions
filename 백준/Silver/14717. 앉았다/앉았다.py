import sys
from decimal import Decimal

score_board = [[0 for _ in range(11)] for _ in range(11)]
for i in range(1, 11):
    for j in range(1, 11):
        if i == j:
            score_board[i][j] = 10+i
        else:
            score_board[i][j] = (i+j)%10
left = [2 for _ in range(11)]
a, b = map(int, sys.stdin.readline().split())
my_score = score_board[a][b]
left[a] -= 1
left[b] -= 1

count = 0
win = 0

for i in range(1, 11):
    for j in range(i, 11):
        if i == j and left[i] == 2:
            count += 1
            if my_score > score_board[i][j]:
                win += 1
        elif i != j and left[i] > 0 and left[j] > 0:
            multiple = left[i]*left[j]
            count += multiple
            if my_score > score_board[i][j]:
                win += multiple
ans = Decimal(win)/Decimal(count)


print(ans.quantize(Decimal('0.001')))