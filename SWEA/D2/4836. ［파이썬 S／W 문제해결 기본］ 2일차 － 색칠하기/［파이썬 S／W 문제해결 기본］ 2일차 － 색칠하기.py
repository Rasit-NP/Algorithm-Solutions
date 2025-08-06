t = int(input())

for tc in range(1, t+1):
    n = int(input())

    setRed = set()
    setBlue = set()

    for _ in range(n):
        r1, c1, r2, c2, color = map(int, input().split())
        if color == 1:
            for i in range(r1, r2+1):
                for j in range(c1, c2+1):
                    setRed.add((i,j))
        else:
            for i in range(r1, r2+1):
                for j in range(c1, c2+1):
                    setBlue.add((i,j))
    
    print(f'#{tc}', len(setRed & setBlue))