import sys, math

def cal_digit(x):
    if x == 0:
        return 0
    log = int(math.log10(x))
    res = 0
    for i in range(1, log+1):
        res += (i+1)*(10**i - 10**(i-1))
    res += (x-10**log+1) * (log+2)
    res -= x//4
    return res

if __name__ == "__main__":
    while True:
        k = int(sys.stdin.readline())
        if not k:
            break
        l = 0; r = 1<<50
        while r-l > 1:
            mid = (l+r) >> 1
            if cal_digit(mid) >= k:
                r = mid
            else:
                l = mid
        target = r
        diff = k - cal_digit(target-1)
        target = list(str(target))
        if diff > len(target):
            if int(target[-1]) & 1:
                ans = 2
            else:
                ans = 0
        else:
            ans = target[diff-1]
        print(ans)