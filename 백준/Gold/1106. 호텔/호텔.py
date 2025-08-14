import sys

c, n = map(int, sys.stdin.readline().split())

promotion = []

for _ in range(n):
    cost, customer = map(int, sys.stdin.readline().split())
    promotion.append((cost, customer))
ans = [float('inf')] * (c + 1)
ans[0] = 0

for i in range(1, c):
    for cost, customer in promotion:
        if i >= customer:
            ans[i] = min(ans[i-customer]+cost, ans[i])

for cost, customer in promotion:
    ans[-1] = min(ans[-1], min(ans[-1-customer:-1])+cost)

print(ans[-1])