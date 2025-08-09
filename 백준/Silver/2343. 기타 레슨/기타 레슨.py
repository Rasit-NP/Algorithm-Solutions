import sys

n, m = map(int, sys.stdin.readline().split())

lst = list(map(int, sys.stdin.readline().split()))

total = sum(lst)
maximum = max(lst)
if m == 1:
    print(total)
elif m == n:
    print(maximum)
else:
    left = maximum-1
    right = total
    test = (left+right)//2
    while right - left > 1:
        def check(lectures, test_num):
            count = 0
            sumation = 0
            for i in range(n-1):
                sumation += lectures[i]
                if sumation+lectures[i+1] > test_num:
                    count += 1
                    sumation = 0
            return count+1

        if check(lst, test) > m:
            left = test
        else:
            right = test
        test = (left+right)//2
    
    print(right)