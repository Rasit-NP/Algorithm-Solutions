import sys

t = int(sys.stdin.readline())
for _ in range(t):
    n, m = map(int, sys.stdin.readline().split())
    dot = 0
    for _ in range(n):
        inputs = list(sys.stdin.readline().rstrip())
        for j in range(m):
            if inputs[j] == '.':
                dot += 1
    if dot&1:
        print('sewon')
    else:
        print('pizza')