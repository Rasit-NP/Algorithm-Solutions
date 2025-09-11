import sys

n = int(sys.stdin.readline())
i = 0
total = 0
while total < n:
    i += 1
    total += i

total -= i
i += 1
loss = n - total
if i%2:
    print(f'{loss}/{i-loss}')
else:
    print(f'{i-loss}/{loss}')