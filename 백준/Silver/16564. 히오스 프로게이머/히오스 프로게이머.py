import sys

def teamlvl(lst, target):
    sum = 0
    for i in range(n):
        a = lst[i]
        if a < target:
            sum += target-a
    return sum

n, k = map(int, sys.stdin.readline().split())
lvls = []
for _ in range(n):
    lvls.append(int(sys.stdin.readline()))

left = 0
right = 10000000000
test = (left+right)//2

while right-left != 1:
    if teamlvl(lvls, test) > k:
        right = test
    else:
        left = test
    test = (left+right)//2

print(left)