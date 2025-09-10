import sys

n = int(sys.stdin.readline())
if not n%2024 and n<=100000:
    print('Yes')
else:
    print('No')