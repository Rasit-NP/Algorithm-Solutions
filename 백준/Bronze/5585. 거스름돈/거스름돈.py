import sys

n = int(sys.stdin.readline())

count = 0
coin = [500, 100, 50, 10, 5, 1]
target = 1000 - n
for i in range(6):
    count += target//coin[i]
    target %= coin[i]

print(count)