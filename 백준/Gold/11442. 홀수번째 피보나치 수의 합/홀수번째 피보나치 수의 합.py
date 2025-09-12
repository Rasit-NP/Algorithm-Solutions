import sys

def product(matA, matB):
    ans_mat = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for d in range(2):
                ans_mat[i][j] += matA[i][d]*matB[d][j]
            ans_mat[i][j] %= 1000000007
    return ans_mat

def square(mat):
    return product(mat, mat)

n = int(sys.stdin.readline())

if n%2:
    n += 1

lst = []
while n:
    lst.append(n%2)
    n //= 2

ans = [[1, 0], [0, 1]]
bias = [[1, 1], [1, 0]]
for i in lst:
    if i:
        ans = product(ans, bias)
    bias = square(bias)

print(ans[0][1])