import sys
from collections import Counter

def action(arr, ord):
    index = 0
    for i in range(len(ord)):
        if ord[i] == 'R':
            if index == 0:  index = -1
            else:   index = 0
        elif ord[i] == 'D':
            arr.pop(index)
    if index == -1:
        arr.reverse()
    return arr

T = int(sys.stdin.readline())
for _ in range(T):
    order = list(sys.stdin.readline().rstrip())     #'r' 'd' 'd'
    n = int(sys.stdin.readline())
    if n > 0:
        array = list(map(int, sys.stdin.readline().rstrip()[1:-1].split(',')))
    else:
        shit = sys.stdin.readline()
        array = []
    if Counter(order)['D'] > n:
        sys.stdout.write("error\n")
    else:
        array = ','.join(map(str, action(array, order)))
        sys.stdout.write("["+array+"]\n")