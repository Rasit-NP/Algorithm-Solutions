import sys

def count(length, lines):
    sum = 0
    for line in lines:
        sum += line // length
    
    return sum

k, n = map(int, sys.stdin.readline().split())
lines = []
maximum = 0

for _ in range(k):
    data = int(sys.stdin.readline())
    lines.append(data)

left = 1
right = 2**31

while right-left != 1:
    test = (left + right) // 2
    if count(test,lines) < n:
        right = test
    else:
        left = test

print(left)