import sys, copy

def matrix_product(matrix1, matrix2):
    new_matrix = [[None]*n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            sum = 0
            for k in range(n):
                sum += matrix1[i][k] * matrix2[k][j]
            new_matrix[i][j] = sum%1000
    return new_matrix

def matrix_square(matrix):
    return matrix_product(matrix, matrix)

n, b = map(int, sys.stdin.readline().split())
matrix = []
binary = []         #[1, 2, 4, 8]
ans = [[0]*n for _ in range(n)]

for i in range(n):
    ans[i][i] = 1
    
for _ in range(n):
    matrix.append(list(map(int, sys.stdin.readline().split())))
    
while b>1:
    binary.append(b%2)
    b //=2
binary.append(b)

for i in range(len(binary)):
    if binary[i] == 1:
        ans = matrix_product(ans, matrix)
    matrix = matrix_square(matrix)

for i in range(n):
    print(' '.join(list(map(str, ans[i]))))