from decimal import Decimal, ROUND_HALF_UP
import sys

def input():
    global n, matrix, constants

    n = int(sys.stdin.readline())
    matrix = [[None for _ in range(n)] for _ in range(n)]
    constants = [None for _ in range(n)]

    for i in range(n):
        inputs = list(map(Decimal, sys.stdin.readline().rstrip().split()))
        for j in range(n):
            matrix[i][j] = inputs[j]
        constants[i] = inputs[-1]

    return

input()

unit = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    unit[i][i] = Decimal(1)

for i in range(n):
    a = matrix[i][i]
    for j in range(n):
        matrix[i][j] = matrix[i][j] / a
        unit[i][j] = unit[i][j] / a
    for di in range(1, n):
        ratio = matrix[i - di][i] / matrix[i][i]
        for j in range(n):
            matrix[i - di][j] -= matrix[i][j] * ratio
            unit[i - di][j] -= unit[i][j] * ratio

ans = [None for _ in range(n)]

for i in range(n):
    ans[i] = Decimal('0')
    for j in range(n):
        ans[i] += unit[i][j]*constants[j]
    ans[i] = ans[i].quantize(Decimal('1'), rounding=ROUND_HALF_UP)

sys.stdout.write(' '.join(map(str, ans)))
sys.stdout.write('\n')