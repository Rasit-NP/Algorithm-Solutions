import sys

n = int(sys.stdin.readline())
money = list(map(int, sys.stdin.readline().split()))
limit = int(sys.stdin.readline())

if sum(money) > limit:
    left, right = 0, limit

    while right-left > 1:
        test = (right + left) // 2
        total = 0
        for mon in money:
            if test > mon:
                total += mon
            else:
                total += test
        if total > limit:
            right = test
        else:
            left = test
    print(left)
else:
    print(max(money))