import sys

inputs = sys.stdin.readlines()

for i in range(len(inputs)-1):
    n = list(inputs[i].rstrip())
    d = len(n)
    check = 1
    for j in range((d+1)//2):
        if n[j] != n[-j-1]:
            check = 0
            break
        else:
            continue
    if check:
        print('yes')
    else:
        print('no')