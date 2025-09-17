import sys

t = int(sys.stdin.readline())

for _ in range(t):
    a, b = map(int, sys.stdin.readline().split())
    lst = []
    x = a%10
    while x not in lst:
        lst.append(x)
        x = (x*a) % 10

    idx = (b-1)%len(lst)
    ans = lst[idx]
    if ans: print(ans)
    else:   print(10)