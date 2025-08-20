from collections import deque

for _ in range(10):
    tc = int(input())
    lst = deque(map(int, input().split()))

    condition = False
    while True:
        for i in range(1, 6):
            num = lst.popleft()
            num -= i
            if num <= 0:
                num = 0
                lst.append(num)
                condition = True
                break
            else:
                lst.append(num)
        if condition:
            break

    print(f'#{tc}', end=' ')
    print(' '.join(map(str, lst)))