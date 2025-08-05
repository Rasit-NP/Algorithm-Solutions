for tc in range(1, 11):
    v, e = map(int, input().split())
    inputs = list(map(int, input().split()))
    edges = []
    while inputs:
        e = inputs.pop()
        s = inputs.pop()
        edges.append((s, e))

    visited = [0]*(v+1)
    terminal = []
    
    while len(terminal)<v:
        for s, e in edges:
            if str(s) not in terminal:
                visited[e] = visited[s] + 1
            else:
                continue

        for i in range(1, v+1):
            if visited[i] == 0:
                terminal.append(str(i))
                visited[i] = -1
            elif visited[i] > 0:
                visited[i] = 0
    
    print(f'#{tc} ',' '.join(terminal))