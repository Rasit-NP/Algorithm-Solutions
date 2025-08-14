import sys

n, x = map(int, sys.stdin.readline().split())

length = [0]*51
pat = [0]*51
for lvl in range(51):
    length[lvl] = 2**(lvl+2)-3
    pat[lvl] = 2**(lvl+1) - 1


def func(lvl, eat):
    if lvl == 1:
        if eat <= 1:
            return 0
        elif 1 < eat <= 5:
            return min(3, eat-1)
    else:
        if eat <= 1:
            return 0
        elif 1 < eat <= length[lvl-1]:
            return func(lvl-1, eat-1)
        elif eat == length[lvl-1] + 1:
            return pat[lvl-1]
        elif eat == length[lvl-1] + 2:
            return pat[lvl-1] + 1
        elif length[lvl-1] + 2 < eat < length[lvl]:
            return pat[lvl-1] + 1 + func(lvl-1, eat-(length[lvl-1]+2))
        elif eat == length[lvl]:
            return pat[lvl]

print(func(n, x))