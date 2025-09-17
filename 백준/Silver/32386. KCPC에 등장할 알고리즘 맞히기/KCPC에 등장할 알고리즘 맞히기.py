import sys

n = int(sys.stdin.readline())
data = {}
for _ in range(n):
    inputs = sys.stdin.readline().rstrip().split()
    t = int(inputs[1])
    for i in range(2, t+2):
        tag = inputs[i]
        if tag in data:
            data[tag] += 1
        else:
            data[tag] = 1

maximum = 0
for tag in data:
    if data[tag] > maximum:
        maximum = data[tag]
        ans = tag
    elif data[tag] == maximum:
        ans = -1

print(ans)