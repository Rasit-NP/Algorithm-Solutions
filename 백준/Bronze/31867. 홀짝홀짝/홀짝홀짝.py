import sys

n = int(sys.stdin.readline())
k = list(map(int, sys.stdin.readline().rstrip()))
count = 0
for num in k:
    if num%2:
        count += 1
    else:
        count -= 1

if count > 0:
    print(1)
elif count < 0:
    print(0)
else:
    print(-1)