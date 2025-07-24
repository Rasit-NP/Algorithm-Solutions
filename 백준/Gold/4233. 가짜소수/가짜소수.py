import sys, math

def isItPrime(n):
    for i in range(2, int(math.sqrt(n))+1):
        if n%i == 0:    return False
    return True

def isItPseudoPrime(n, a):  ## n이 합성수인 경우만 검증
    if pow(a, n, n) == a:   return True
    else:   False


while True:
    x, y = map(int, sys.stdin.readline().split())

    if x == 0 and y == 0:
        break

    if not isItPrime(x) and isItPseudoPrime(x, y):
        sys.stdout.write('yes\n')
    else:   sys.stdout.write('no\n')