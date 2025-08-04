import sys

n = int(sys.stdin.readline())

cost = [[]]*n
for i in range(n):
    cost[i] = list(map(int, sys.stdin.readline().split()))
lst = []
minimum = float('inf')
sum_lst = [[]]*n
sum_lst[0] = (cost[0][0], cost[0][1], cost[0][2])
for i in range(1,n):
    sum_lst[i] = (cost[i][0]+min(sum_lst[i-1][1],sum_lst[i-1][2]),
                  cost[i][1]+min(sum_lst[i-1][0],sum_lst[i-1][2]),
                  cost[i][2]+min(sum_lst[i-1][0],sum_lst[i-1][1]))

print(min(sum_lst[-1]))