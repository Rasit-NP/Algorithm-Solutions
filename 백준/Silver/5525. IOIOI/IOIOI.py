import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())
word = sys.stdin.readline().rstrip()

idx = 0
count = 0
check = 0
if m >= 2*n + 1:
    while idx < m:
        if check % 2 == 0 and word[idx] == 'I':
            check += 1
            if check >= 2*n+1:
                count += 1
        elif check % 2 == 1 and word[idx] == 'O':
            check += 1
        elif check % 2 == 1 and word[idx] == 'I':
            check = 1
        else:
            check = 0
        idx += 1
    print(count)
else:
    print(0)