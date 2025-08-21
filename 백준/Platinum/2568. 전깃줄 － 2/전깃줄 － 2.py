import sys

def input():
    n = int(sys.stdin.readline())
    wires = []
    for _ in range(n):
        a, b = map(int, sys.stdin.readline().split())
        wires.append((a, b))
    wires.sort()
    return n, wires

n, wires = input()

tail = []
pos = []
prev = []
tail_idx = []

for i in range(n):
    a, b = wires[i]
    length = len(tail)
    if length == 0:
        tail.append(b)
        pos.append(0)
        prev.append(None)
        tail_idx.append(i)
    else:
        if b > tail[-1]:
            tail.append(b)
            pos.append(length)
            prev.append(tail_idx[-1])
            tail_idx.append(i)
        else:
            left, right = -1, length-1
            while right-left > 1:
                test = (right+left)//2
                if b <= tail[test]:
                    right = test
                else:
                    left = test
            pos.append(right)
            tail[right] = b
            prev.append(tail_idx[right-1]) if right>0 else prev.append(None)
            tail_idx[right] = i

ans = []
idx = tail_idx[-1]

while idx != None:
    ans.append(idx)
    idx = prev[idx]


ans.reverse()
print(n-len(tail))

k = 0
for i in range(n):
    if k >= len(ans):
        print(wires[i][0])
        continue
    if i < ans[k]:
        print(wires[i][0])
    elif i > ans[k]:
        while i > ans[k]:
            k += 1
        if i == ans[k]:
            continue
        elif i < ans[k]:
            print(wires[i][0])
    elif i == ans[k]:
        k += 1