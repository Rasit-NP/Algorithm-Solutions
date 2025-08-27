import sys

n, m = map(int, sys.stdin.readline().split())
nums = sorted(list(set(map(int, sys.stdin.readline().split()))))

def backtracking(lst):
    if len(lst) == m:
        print(' '.join(map(str, lst)))
    else:
        for num in nums:
            if len(lst) == 0 or num >= lst[-1]:
                lst.append(num)
                backtracking(lst)
                lst.pop()

backtracking([])