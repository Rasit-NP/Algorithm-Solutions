import sys

n = int(sys.stdin.readline())

for _ in range(n):
    inputs = sys.stdin.readline().rstrip()
    count = 0
    for i in range(len(inputs)):
        if inputs[i] == 'g' or inputs[i] == 'G':
            count += 1
        elif inputs[i] == 'b' or inputs[i] == 'B':
            count -= 1
    print(f'{inputs} is', end=' ')
    if count > 0:
        print('GOOD')
    elif count == 0:
        print('NEUTRAL')
    else:
        print('A BADDY')