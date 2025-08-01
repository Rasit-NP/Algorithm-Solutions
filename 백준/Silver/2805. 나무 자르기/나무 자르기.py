import sys

def how_long(height, trees):
    sum = 0
    for tree in trees:
        if tree > height:
            sum += (tree-height)
    return sum

n, m = map(int, sys.stdin.readline().split())

trees = list(map(int, sys.stdin.readline().split()))

left = 0
right = 2000000000

while right - left != 1:
    test = (right + left)//2
    if how_long(test, trees)<m:
        right = test
    else:
        left = test

print(left)