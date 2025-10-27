import sys
from math import sqrt

n = int(sys.stdin.readline())
m = n
ans = n
check_max = int(sqrt(n))
arith = [True for _ in range(check_max+1)]
arith[0] = False
arith[1] = False

if n==1:
    print(1)
else:
    prime = [2]
    insu = set()
    for i in range(2, check_max + 1):
        if not arith[i]:
            continue
        for k in range(2*i, check_max+1, i):
            arith[k] = False
        prime.append(i)
        while not m%i:
            insu.add(i)
            m //= i
    if m > 1:
        insu.add(m)
    insu = tuple(insu)
    length = len(insu)
    for k in range(1, 1<<length):
        cnt = 0
        num = 1
        for i in range(length):
            if k & (1<<i):
                cnt += 1
                num *= insu[i]
        if cnt&1:
            ans -= n // num
        else:
            ans += n // num
    print(ans)