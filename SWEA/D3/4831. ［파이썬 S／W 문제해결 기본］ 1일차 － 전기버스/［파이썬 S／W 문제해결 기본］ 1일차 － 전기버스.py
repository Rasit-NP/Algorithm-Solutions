t = int(input())

for tc in range(1, t+1):
    k, n, m = map(int, input().split())
    charges = list(map(int, input().split()))+[n]

    points = [float('inf')]* (n+k+1)
    points[0] = 0
    for i in range(n+1):
        for j in range(1, k+1):
            if i+j in charges:
                points[i+j] = min(points[i+j], points[i]+1)
    
    if points[n] == float('inf'):
        print(f'#{tc}', 0)
    else:
        print(f'#{tc}', points[n]-1)