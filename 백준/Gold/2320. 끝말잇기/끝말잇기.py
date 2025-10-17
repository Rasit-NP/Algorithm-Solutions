import sys
sys.setrecursionlimit(1<<20)

def dp(state, x):
    if (state, x) in memo:
        return memo[(state, x)]
    total = lens[x]
    for nx in edges[x]:
        if not state&(1<<nx):
            new_state = state | (1<<nx)
            total = max(total, lens[x] + dp(new_state, nx))
    memo[(state, x)] = total
    return total

n = int(sys.stdin.readline())
words = []
lens = []
edges = [[] for _ in range(n)]
memo = {}

for _ in range(n):
    word = sys.stdin.readline().rstrip()
    words.append((word[0], word[-1]))
    lens.append(len(word))

for i in range(n):
    for j in range(i+1, n):
        if words[i][0] == words[j][1]:
            edges[j].append(i)
        if words[i][1] == words[j][0]:
            edges[i].append(j)
words.clear()

ans = 0
for i in range(n):
    ans = max(ans, dp(1<<i, i))

print(ans)