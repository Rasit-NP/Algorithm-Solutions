import sys

g = int(sys.stdin.readline())
p = int(sys.stdin.readline())
gates = [i for i in range(g+1)]
ans = 0

def find(x):
    root = x
    while gates[root] != root:
        gates[root] = gates[gates[root]]
        root = gates[root]
    return root

ans = 0
state = True
for count in range(p):
    g_i = int(sys.stdin.readline())
    if state:
        root = find(g_i)
        if root == 0:
            ans = count
            state = False
        gates[root] = root - 1

if state:
    print(count+1)
else:
    print(ans)