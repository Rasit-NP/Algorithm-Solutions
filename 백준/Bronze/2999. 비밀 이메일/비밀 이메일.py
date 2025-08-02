import sys

inputs = sys.stdin.readline().rstrip()
r, c = 1, len(inputs)

for i in range(1, len(inputs)+1):

    if len(inputs) % i == 0 and i <= len(inputs)//i:
        r, c = i, len(inputs)//i
    elif i > len(inputs)/i:
        break

ans = ''
for i in range(r):
    for j in range(c):
        ans += inputs[j*r + i]
print(ans)