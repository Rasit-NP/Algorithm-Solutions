t = int(input())

for tc in range(1, t+1):
    n = int(input())
    inputs = list(map(int, input().split()))

    for i in range(n-1):
        for j in range(n-1-i):
            inputs[j], inputs[j+1] = min(inputs[j], inputs[j+1]), max(inputs[j], inputs[j+1])
    


    print(f'#{tc}', end=' ')
    print(' '.join(list(map(str, inputs))))