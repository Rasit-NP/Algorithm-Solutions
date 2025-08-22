import sys

def input():
    n = int(sys.stdin.readline())
    lst = list(map(int, sys.stdin.readline().split()))
    m = int(sys.stdin.readline())
    question = []
    for _ in range(m):
        s, e = map(int, sys.stdin.readline().split())
        question.append((s-1, e-1))
    
    return n, m, lst, question

n, m, nums, questions = input()

dp = [[None] * n for _ in range(n)]

for i in range(n):
    dp[i][i] = True
    if i < n-1:
        if nums[i] == nums[i+1]:
            dp[i][i+1] = True
        else:
            dp[i][i+1] = False

def func(x, y, lst):
    if dp[x][y] is not None:
        return dp[x][y]
    else:
        if func(x+1, y-1, lst):
            if lst[x] == lst[y]:
                dp[x][y] = True
                return True
            else:
                dp[x][y] = False
                return False
        else:
            dp[x][y] = False
            return False

for s, e in questions:
    if dp[s][e] == None:
        if func(s, e, nums):
            print(1)
        else:
            print(0)
    elif dp[s][e]:
        print(1)
    else:
        print(0)