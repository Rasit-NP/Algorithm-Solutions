import sys

n = int(sys.stdin.readline())

lst = list(map(int, sys.stdin.readline().split()))

for _ in range(n-1):
    lst += list(map(int,sys.stdin.readline().split()))
    lst.sort()
    lst = lst[-n:]

print(lst[0])