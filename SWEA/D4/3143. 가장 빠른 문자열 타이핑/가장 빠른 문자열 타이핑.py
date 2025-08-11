t = int(input())

for tc in range(1, t+1):
    str1, str2 = input().split()
    i = 0
    a = len(str1)
    b = len(str2)
    count = 0
    while i < a:
        if str1[i:i+b] == str2:
            i += b
            count += 1
        else:
            i += 1
            count += 1

    print(f'#{tc}', end=' ')
    print(count)