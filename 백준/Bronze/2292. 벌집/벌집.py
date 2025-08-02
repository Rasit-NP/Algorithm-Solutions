import sys

n = int(sys.stdin.readline())

i = 0
a = 0
b = 1

while not a < n <= b:
    i += 1
    a = 1 + 3 * (i-1) * i
    b = 1 + 3 * i * (i+1)

print(i+1)