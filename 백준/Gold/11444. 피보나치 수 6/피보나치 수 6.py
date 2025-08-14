import sys

def product(matrixa, matrixb, mod=1000000007):
    ans = [[None, None],[None, None]]
    for i in range(2):
        for j in range(2):
            sum = 0
            for k in range(2):
                sum += matrixa[i][k]*matrixb[k][j]
            ans[i][j] = sum % mod
    return ans

def square(matrix):
    return product(matrix, matrix)

n = int(sys.stdin.readline())

Q = [[1, 1], [1, 0]]
binary = []

total = [[1, 0], [0, 1]]

while n:
    binary.append(n%2)
    n //= 2

for i in range(len(binary)):
    if binary[i] == 1:
        total = product(total, Q)
    Q = square(Q)

print(total[1][0])