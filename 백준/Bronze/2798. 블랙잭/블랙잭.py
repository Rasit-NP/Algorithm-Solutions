import sys

n, m = map(int, sys.stdin.readline().split())
cards = list(map(int, sys.stdin.readline().split()))

maximum = 0
lst = []
selected = []
def backtracking(cards):
    global maximum
    if len(lst) == 3 and sum(selected)<=m:
        maximum = max(maximum, sum(selected))
    else:
        for i in range(n):
            if i not in lst and sum(selected) < m:
                lst.append(i)
                selected.append(cards[i])
                backtracking(cards)
                lst.pop()
                selected.pop()

backtracking(cards)

print(maximum)