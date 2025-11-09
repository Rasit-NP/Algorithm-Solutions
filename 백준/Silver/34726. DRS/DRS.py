import sys

n, t = map(int, sys.stdin.readline().split())
state = []
for _ in range(n):
    name, pos = sys.stdin.readline().rstrip().split()
    pos = int(pos)
    if pos:
        pos = (state[-1][0] + pos) % t
    state.append((pos, name))

state.sort()
ans = []
for i in range(n):
    name = state[i][1]
    if i == 0:
        if t-1000<=state[-1][0]<t:
            ans.append(name)
    else:
        if 0<state[i][0] - state[i-1][0] <= 1000:
            ans.append(name)
if ans:
    ans.sort()
    print(' '.join(map(str, ans)))
else:
    print(-1)