import sys

def cooling(test, computers):
    total = 0
    for i in range(n**2):
        if test > computers[i]:
            total += computers[i]
        else:
            total += test
    return total

n = int(sys.stdin.readline())
computers = []

for i in range(n):
    computers += list(map(int, sys.stdin.readline().split()))

goal = (sum(computers)+1) // 2

left, right = 0, max(computers)
if right != 0:
    while right-left > 1:
        test = (left + right)//2
        num = cooling(test, computers)
        if num >= goal:
            right = test
        else:
            left = test
    print(right)
else:
    print(0)