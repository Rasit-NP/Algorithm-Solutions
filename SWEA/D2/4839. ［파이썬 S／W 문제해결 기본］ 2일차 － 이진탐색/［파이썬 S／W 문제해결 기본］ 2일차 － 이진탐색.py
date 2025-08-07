t = int(input())

for tc in range(1, t+1):

    print(f'#{tc}', end=' ')
    p, a, b = map(int, input().split())

    lefta, leftb = 1, 1
    righta, rightb = p, p
    testa = (lefta + righta)//2
    testb = (leftb + rightb)//2

    while testa != a and testb != b:
        if testa > a:
            righta = testa
        elif testa < a:
            lefta = testa
        if testb > b:
            rightb = testb
        elif testb < b:
            leftb = testb
        testa = (lefta + righta)//2
        testb = (leftb + rightb)//2
    
    if testa == a and testb == b:
        print(0)
    elif testa == a:
        print('A')
    else:
        print('B')