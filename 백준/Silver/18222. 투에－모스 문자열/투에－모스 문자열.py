import sys

def check(k):
    left, right = 0, 60
    test = (left+right)//2

    while right-left > 1:
        if k <= 2 ** test:
            right = test
        else:
            left = test
        test = (left+right)//2

    return left

k = int(sys.stdin.readline())

i = 0

while True:
    if k == 1:
        break
    n = check(k)
    k = k - 2**check(k)
    i += 1

if i % 2 == 0:
    print(0)
else:
    print(1)