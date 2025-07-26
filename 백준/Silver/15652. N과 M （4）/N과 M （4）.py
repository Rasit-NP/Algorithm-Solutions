import sys
sys.setrecursionlimit(10**6)

def func(arr):
    if len(arr) == m:
        sys.stdout.write(' '.join(list(map(str, arr)))+'\n')
        ans.pop()
    else:
        for i in range(arr[-1],n+1):
            arr.append(i)
            func(arr)
        ans.pop()

n, m = map(int, sys.stdin.readline().split())
ans = []

for i in range(1,n+1):
    ans.append(i)
    func(ans)