import sys

n = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))
ans = [1] * n

for i in range(n):
    for j in range(i, n):
        if lst[j] > lst[i]:
            ans[j] = max(ans[j], ans[i]+1)
    
print(max(ans))