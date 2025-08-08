from collections import Counter
t = int(input())

for tc in range(1, t+1):
    str1 = list(set(input()))
    str2 = list(input())

    count = dict(Counter(str2))
    maximum = 0
    for i in str1:
        maximum = max(count[i], maximum)

    print(f'#{tc}', end=' ')
    print(maximum)