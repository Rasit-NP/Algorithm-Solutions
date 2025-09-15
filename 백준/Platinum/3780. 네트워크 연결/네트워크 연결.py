import sys

def main():
    global n, parents
    n = int(sys.stdin.readline())
    parents = [i for i in range(n+1)]

    while True:
        inputs = list(sys.stdin.readline().rstrip().split())
        oper = inputs[0]
        if oper == 'I':
            oper_I(int(inputs[1]), int(inputs[2]))
        elif oper == 'E':
            oper_E(int(inputs[1]))
        else:
            break

def find(x):
    root = x
    while root != parents[root]:
        root = parents[root]
    return root


def oper_I(i, j):
    ri = find(i)
    parents[ri] = j
    return

def oper_E(i):
    root = i
    dist = 0
    while root != parents[root]:
        dist += abs(root-parents[root]) % 1000
        root = parents[root]
    print(dist)
    return

if __name__=="__main__":
    t = int(sys.stdin.readline())
    for _ in range(t):
        main()