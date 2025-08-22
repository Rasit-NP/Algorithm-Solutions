import sys

def input():
    lst = sys.stdin.readline().rstrip()
    length = len(lst)
    dp = [[None]*length for _ in range(length)]

    for i in range(length):
        dp[i][i] = True
        if i == length-1:
            break
        if lst[i] == lst[i+1]:
            dp[i][i+1] = True
        else:
            dp[i][i+1] = False

    for j in range(2, length):
        x, y = 0, j
        while y < length:
            if dp[x+1][y-1] and lst[x] == lst[y]:
                dp[x][y] = True
            else:
                dp[x][y] = False
            x += 1
            y += 1

    return lst, length, dp

lst, length, dp = input()

ans = [0] * length

for i in range(length):
    if dp[0][i]:
        ans[i] = 0
    else:
        minimum = i
        for j in range(i):
            if dp[j+1][i]:
                minimum = min(minimum, ans[j]+1)
        ans[i] = minimum

print(ans[-1]+1)