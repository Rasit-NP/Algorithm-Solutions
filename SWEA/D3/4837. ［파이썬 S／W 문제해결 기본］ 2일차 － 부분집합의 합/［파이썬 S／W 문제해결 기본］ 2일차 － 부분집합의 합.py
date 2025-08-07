t = int(input())

for tc in range(1, t+1):
    
    def combination(lst):
        global count
        if len(lst) == n:
            if sum(lst) == k:
                count += 1
        elif sum(lst) > k:
            return
        elif len(lst) > 0:
            for i in range(lst[-1],13):
                if i not in sets:
                    lst.append(i)
                    sets.add(i)
                    combination(lst)
                    sets.remove(i)
                    lst.pop()
        elif len(lst) == 0:
            for i in range(1, 13):
                lst.append(i)
                sets.add(i)
                combination(lst)
                sets.remove(i)
                lst.pop()

    n, k = map(int, input().split())
    
    lst = []
    sets = set()
    count = 0
    combination(lst)
    

    print(f'#{tc}', end=' ')
    print(count)