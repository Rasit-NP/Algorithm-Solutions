from collections import deque

t = int(input())

for tc in range(1, t+1):
    def find(n):
        if n == 1:
            return 1
        elif 2 <= n <= 3:
            return 2
        elif 4<= n < 8:
            return 3
        elif 8<= n < 16:
            return 4
        elif 16<= n<=20:
            return 5
        
    n, m = map(int, input().split())
    pizzas = list(map(int, input().split()))
    pizzas = deque(map(find, pizzas))
    oven = [None] * n
    idx = [None] * n
    for i in range(n):
        a = pizzas.popleft()
        oven[i] = a
        idx[i] = i+1

    while pizzas:
        a = pizzas.popleft()
        minimum = float('inf')
        idx_min = 0
        for i in range(n):
            if oven[i] < minimum:
                minimum = oven[i]
                idx_min = i
        oven[idx_min] += a
        idx[idx_min] = m-len(pizzas)
    
    maximum = 0
    for i in range(n):
        if oven[i] >= maximum:
            maximum = oven[i]
            idx_max = i
    
    print(f'#{tc}', end=' ')
    print(idx[idx_max])