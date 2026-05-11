import math

t = int(input())
for _ in range(t):
    s, p = map(int, input().split())
    sq = s**2 - 4*p
    rt = int(math.sqrt(sq))

    if (rt**2 != sq):
        print("No")
        continue
    else:
        a = s+rt
        b = s-rt
        if b <= 0:
            print("No")
            continue
        if (a&1) or (b&1):
            print("No")
            continue
        else:
            print("Yes")
            continue