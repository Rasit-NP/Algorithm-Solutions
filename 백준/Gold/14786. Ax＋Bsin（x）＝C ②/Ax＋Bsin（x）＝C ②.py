import sys, math

a, b, c = map(int, sys.stdin.readline().split())

left = (c-b)//a
right = (c+b)//a + 1

for _ in range(100):
    test = (left+right)/2
    cal = a*test + b*math.sin(test)

    if cal < c:
        left = test
    elif cal > c:
        right = test

print((left+right)/2)