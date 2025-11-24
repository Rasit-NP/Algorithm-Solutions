import sys

n = int(sys.stdin.readline())

lst = list(map(int, sys.stdin.readline().split()))

forv = int(sys.stdin.readline())


cnt = 0
for x in lst:
    if x == forv:
        cnt += 1



print(cnt)