t= int(input())

for tc in range(1, t+1):
    str1 = input()
    str2 = input()
    a = len(str1)
    b = len(str2)

    ans = 0

    for i in range(b-a+1):
        if str1 == str2[i:i+a]:
            ans = 1

    print(f'#{tc}', end= ' ')
    print(ans)