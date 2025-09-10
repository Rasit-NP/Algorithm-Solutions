import sys

while True:
    n = int(sys.stdin.readline())
    if n:
        print(n*(n+1)*(2*n+1)//6)
    else:
        break