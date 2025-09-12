import sys

def product(matA, matB):
    ans_mat = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for d in range(2):
                ans_mat[i][j] += matA[i][d]*matB[d][j]
            ans_mat[i][j] %= 1000000000
    return ans_mat

def square(mat):
    return product(mat, mat)

def binary(n):
    lst = []
    while n:
        lst.append(n%2)
        n //= 2
    return lst

def fibo(n):
    ans = [[1, 0], [0, 1]]
    bias = [[1, 1], [1, 0]]
    for i in binary(n):
        if i:
            ans = product(ans, bias)
        bias = square(bias)
    return ans[0][1]

def F(n):
    return fibo(n+1)+fibo(n)-1

a, b = map(int, sys.stdin.readline().split())

ans = F(b)-F(a-1)
print(ans if ans>0 else (ans+1000000000))