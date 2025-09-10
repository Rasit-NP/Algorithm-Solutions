import sys

n = int(sys.stdin.readline())

for _ in range(n):
    inputs_a = list(map(int, sys.stdin.readline().split()))
    counts_a = [None] + [0 for _ in range(4)]
    for i in range(1, inputs_a[0]+1):
        counts_a[inputs_a[i]] += 1
    inputs_b = list(map(int, sys.stdin.readline().split()))
    counts_b = [None] + [0 for _ in range(4)]
    for i in range(1, inputs_b[0]+1):
        counts_b[inputs_b[i]] += 1

    for i in range(4, 0, -1):
        if counts_a[i] > counts_b[i]:
            print('A')
            break
        elif counts_b[i] > counts_a[i]:
            print('B')
            break
        elif i == 1 and counts_a[i] == counts_b[i]:
            print('D')
        else:
            continue