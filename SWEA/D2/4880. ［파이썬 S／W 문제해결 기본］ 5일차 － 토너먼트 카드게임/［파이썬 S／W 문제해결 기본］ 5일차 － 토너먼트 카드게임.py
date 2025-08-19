t = int(input())

for tc in range(1, t+1):
    
    n = int(input())
    lst = [None] + list(map(int, input().split()))

    def competition(start, last):
        def game(i, j):
            if lst[i] == lst[j]:
                return i
            elif lst[j] > lst[i]:
                if lst[i]*lst[j] == 3:
                    return i
                else:
                    return j
            elif lst[i] > lst[j]:
                if lst[i]*lst[j] == 3:
                    return j
                else:
                    return i
        if start == last:
            return start
        elif last-start == 1:
            return game(start, last)
        else:
            mid = (start+last)//2
            left = competition(start, mid)
            right = competition(mid+1, last)
            return game(left, right)
    ans = competition(1, n)
    print(f'#{tc}', end=' ')
    print(ans)