import sys

n = int(sys.stdin.readline())

inputs = list(sys.stdin.readline().rstrip())

CountCouple = 0

while len(inputs)>0:
    left = inputs[0]
    if left == 'S':
        if len(inputs) > 1:
            inputs = inputs[1:]
        else:
            break
    elif left == 'L':
        CountCouple += 1
        if len(inputs) > 2:
            inputs = inputs[2:]
        else:
            break

if CountCouple > 1:
    print(n - (CountCouple-1))
else:
    print(n)