import sys

def check(test_board):
    lst = []
    for i in range(len(test_board[0])):
        letter = ''
        for j in range(len(test_board)):
            letter += test_board[j][i]
        lst.append(letter)
    if len(lst) == len(set(lst)):
        return True
    else:
        return False

r, c = map(int, sys.stdin.readline().split())
board = [None]*r

for i in range(r):
    board[i] = list(sys.stdin.readline().rstrip())

left, right = 0, r
test = (left+right)//2

while right-left != 1:
    if check(board[test:]):
        left = test
    else:
        right = test
    test = (left+right)//2
print(left)