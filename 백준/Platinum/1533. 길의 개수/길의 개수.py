import sys

def init():
    global N, n, s, e, t, matrix
    n, s, e, t = map(int, sys.stdin.readline().split())
    N = 5*n
    matrix = [[0]*(N) for _ in range(N)]
    inputs = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(n)]
    for i in range(n):
        for j in range(n):
            T = inputs[i][j]
            if T>0:
                matrix[i][j+(T-1)*n] = 1
    for x in range(n, N):
        matrix[x][x-n] = 1

def product(n, matrix1, matrix2):
    new_matrix = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(n):
            sum = 0
            for h in range(n):
                sum += matrix1[i][h]*matrix2[h][j]
                sum %= 1000003
            new_matrix[i][j] = sum
    return new_matrix

def cal(t, matrix):
    bias = [[0]*(N) for _ in range(N)]
    ans = [[0]*(N) for _ in range(N)]
    for i in range(N):
        ans[i][i] = 1
        for j in range(N):
            bias[i][j] = matrix[i][j]
    
    for i in range(31):
        if t&(1<<i):
            ans = product(N, ans, bias)
        bias = product(N, bias, bias)
    print(ans[s-1][e-1])

if __name__ == "__main__":
    init()
    cal(t, matrix)