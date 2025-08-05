import sys

n = int(sys.stdin.readline())
for tc in range(1, n+1):

    def bellman_ford(n, start, edges):
        visited = [float('inf')]*(n+1)
        visited[start] = 0
        chain_list = []
        for _ in range(n-1):
            for s, e, t in edges:
                if visited[e] > visited[s] + t:
                    visited[e] = visited[s] + t
        
        for s, e, t in edges:
            if visited[e] > visited[s] + t:
                chain_list.append(e)

        for _ in range(n-1):
            for s, e, t in edges:
                if s in chain_list:
                    chain_list.append(e)
        return chain_list

    
    p, s = map(int, sys.stdin.readline().split())
    names = sys.stdin.readline().rstrip().split()
    names = [None] + names
    contacts = []
    for i in range(1, p+1):
        inputs = list(map(int, sys.stdin.readline().split()))
        if len(inputs) > 1:
            for j in inputs[1:]:
                contacts.append((i,j,-1))


    chain_list = []
    chain_list += bellman_ford(p, s, contacts)
    
    ans = [names[i] for i in sorted(list(set(chain_list)))]

    print(f'Chain Email #{tc}:')
    if len(ans) != 0:
        print(' '.join(ans))
    else:
        print('Safe chain email!')
    if tc<n:
        print('')