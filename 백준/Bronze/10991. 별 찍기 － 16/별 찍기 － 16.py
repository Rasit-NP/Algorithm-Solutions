import sys

n = int(sys.stdin.readline())

def star(a):
    if a == 1:
        return '* '
    else:
        return star(a-1)+'* '

for i in range(1, n+1):
    ans = ' '*(n-i)
    ans += star(i)
    print(ans[:-1])