t = int(input())

for tc in range(1, t+1):
    inputs = list(input().rstrip())
    ans = 1
    for i in range(len(inputs)):
        if inputs[i] == inputs[-i-1]:
            continue
        else:
            ans = 0
            break


    print(f'#{tc}', end=' ')
    print(ans)