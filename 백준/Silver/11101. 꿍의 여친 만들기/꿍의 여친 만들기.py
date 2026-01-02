import sys

def solve():
    conditions = sys.stdin.readline().rstrip().split(',')
    for condition in conditions:
        name, cost = condition.split(':')
        condition_map[name] = int(cost)
    combines = sys.stdin.readline().rstrip().split('|')
    mini = float('inf')
    for combine in combines:
        names = combine.split('&')
        maxi = 0
        for name in names:
            maxi = max(maxi, condition_map[name])
        mini = min(mini, maxi)
    return str(mini)

t = int(sys.stdin.readline())
for tc in range(1, t+1):
    condition_map = {}
    sys.stdout.write(solve()+'\n')