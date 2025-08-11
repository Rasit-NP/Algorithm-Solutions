import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
word = sys.stdin.readline().rstrip()

find = 'IO'*n + 'I'

idx = 0
count = 0
while idx <= m - (2*n+1):
    if word[idx:idx+(2*n+1)] == find:
        count += 1
        idx += 2
    else:
        idx += 1

print(count)