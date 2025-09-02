import sys

by, bm, bd = map(int, sys.stdin.readline().split())
ty, tm, td = map(int, sys.stdin.readline().split())

ans = [None]*3
if bm<tm or (bm==tm and bd<=td):
    ans[0] = ty-by
else:
    ans[0] = ty-by-1
ans[1] = ty-by+1
ans[2] = ty-by

print('\n'.join(map(str, ans)))