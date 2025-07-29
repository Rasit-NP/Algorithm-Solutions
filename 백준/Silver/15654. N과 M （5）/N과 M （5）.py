import sys

def func(lst):
    global ans
    if len(ans) == m:
        sys.stdout.write(' '.join(list(map(str, ans)))+'\n')
    else:
        for i in lst:
            if i not in ans:
                ans.append(i)
                func(lst)
                ans.pop()

n, m = map(int, sys.stdin.readline().split())

lst = sorted(list(map(int, sys.stdin.readline().split())))
ans = []

func(lst)