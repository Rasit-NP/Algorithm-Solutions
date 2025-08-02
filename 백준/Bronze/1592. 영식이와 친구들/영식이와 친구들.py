import sys

n, m, l = map(int, sys.stdin.readline().split())

count = [0]*n
count[0] = 1
position = 0
throw = 0

while m not in count:
    if count[position] % 2 == 1:
        position += l
    else:
        position -= l
    if position >= n:
        position -= n
    elif position <0:
        position += n
    throw += 1
    count[position] += 1

print(throw)