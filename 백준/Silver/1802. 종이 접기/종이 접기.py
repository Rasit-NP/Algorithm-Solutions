import sys

def check(inputs):
    length = len(inputs)
    if length == 1:
        print('YES')
    else:
        for i in range((length-1)//2):
            if inputs[i] != inputs[length-i-1]:
                continue
            else:
                print('NO')
                return
        check(inputs[:(length-1)//2])
        
t = int(sys.stdin.readline())

for _ in range(t):
    inputs = list(sys.stdin.readline().rstrip())
    check(inputs)