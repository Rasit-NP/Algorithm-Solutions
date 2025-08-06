import sys

t = int(sys.stdin.readline())
for _ in range(t):
    def cal_exp(n):
        return n*(n-1)
    
    n = int(sys.stdin.readline())

    exp = (n*(n+1))//2

    left, right = 0, 10**9
    while right-left>1:
        test = (left+right)//2
        exp_test = cal_exp(test)
        if exp < exp_test:
            right = test
        else:
            left = test
    
    print(left)