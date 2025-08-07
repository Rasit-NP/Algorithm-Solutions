t = int(input())

for tc in range(1, t+1):
    n = int(input())
    inputs = list(map(int, input().split()))

    def list_min(lst):
        for i in range(1, len(lst)):
            if lst[0] > lst[i]:
                lst[0], lst[i] = lst[i], lst[0]
        
        return lst
    
    def list_max(lst):
        for i in range(1, len(lst)):
            if lst[0] < lst[i]:
                lst[0], lst[i] = lst[i], lst[0]
        return lst

    ans = []

    while inputs and len(ans)<10:
        inputs = list_max(inputs)
        ans += [str(inputs[0])]
        if inputs:
            inputs.pop(0)
            inputs = list_min(inputs)
            ans += [str(inputs[0])]
            if inputs:
                inputs.pop(0)


    print(f'#{tc}', end=' ')
    print(' '.join(ans))