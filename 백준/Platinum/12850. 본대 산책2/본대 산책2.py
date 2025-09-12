import sys

# 0~7
# 정보과학관, 전산관, 미래관, 신양관, 진리관, 한경직기념관, 학생회관, 형남공학관

def product(matrixA, matrixB):
    matrix_ans = [[0 for _ in range(8)] for _ in range(8)]
    for i in range(8):
        for j in range(8):
            for k in range(8):
                matrix_ans[i][j] += matrixA[i][k]*matrixB[k][j]
            matrix_ans[i][j] %= 1000000007
    return matrix_ans

def square(matrix):
    return product(matrix, matrix)

def binary(n):
    lst = []
    while n:
        lst.append(n%2)
        n //= 2
    return lst

edges = [(1, 2), (0, 2, 3), (0, 1, 3, 5), (1, 2, 4, 5), (3, 5, 6), (2, 3, 4, 7), (4, 7), (5, 6)]

matrix = [[0 for _ in range(8)] for _ in range(8)]

for i in range(8):
    for j in edges[i]:
        matrix[i][j] = 1

d = int(sys.stdin.readline())

ans = [[0 for _ in range(8)] for _ in range(8)]
for i in range(8):
    ans[i][i] = 1

bias = matrix

for i in binary(d):
    if i:
        ans = product(ans, bias)
    bias = square(bias)

print(ans[0][0])