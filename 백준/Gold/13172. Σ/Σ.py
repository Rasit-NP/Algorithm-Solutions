import sys

def calculateSquare(down, up, mod):
    binary = []
    ans = 1
    now = down
    
    while up >= 1:
        binary.append(up%2)
        up = up // 2
    
    for i in range(len(binary)):
        if binary[i] == 1:
            ans *= now
            ans %= mod
        now = (now**2) % mod
    return ans

def modInverse(a, x):
    ans = calculateSquare(a, x-2, x)
    return ans

m = int(sys.stdin.readline())
total = 0

for i in range(m):
    n, s = map(int, sys.stdin.readline().split())
    total = (total + s*modInverse(n, 1000000007)) % 1000000007

print(total)