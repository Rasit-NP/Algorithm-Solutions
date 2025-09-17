import sys

n = int(sys.stdin.readline())

r, g, b = map(int, sys.stdin.readline().split())
dpr = [r, float('inf'), float('inf')]
dpg = [float('inf'), g, float('inf')]
dpb = [float('inf'), float('inf'), b]

for _ in range(n-1):
    r, g, b = map(int, sys.stdin.readline().split())
    dpr = [r+min(dpr[1], dpr[2]), g+min(dpr[0], dpr[2]), b+min(dpr[0], dpr[1])]
    dpg = [r+min(dpg[1], dpg[2]), g+min(dpg[0], dpg[2]), b+min(dpg[0], dpg[1])]
    dpb = [r+min(dpb[1], dpb[2]), g+min(dpb[0], dpb[2]), b+min(dpb[0], dpb[1])]

ans = min(min(dpr[1], dpr[2]), min(dpg[0], dpg[2]), min(dpb[0], dpb[1]))

print(ans)