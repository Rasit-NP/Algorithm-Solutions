import sys

def printing(n):
    if n == 0:
        sys.stdout.write('-')
    else:
        printing(n-1)
        sys.stdout.write(' '*(3**(n-1)))
        printing(n-1)

inputs = list(map(int, sys.stdin.readlines()))

for n in inputs:
    printing(n)
    sys.stdout.write('\n')