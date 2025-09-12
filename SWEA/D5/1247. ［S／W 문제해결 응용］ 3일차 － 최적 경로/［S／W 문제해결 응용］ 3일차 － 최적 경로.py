t = int(input())

for tc in range(1, t+1):

    def dist(pos1, pos2):
        x1, y1 = pos1
        x2, y2 = pos2
        return abs(x2-x1)+abs(y2-y1)
    
    print(f'#{tc}', end=' ')

    n = int(input())
    inputs = list(map(int, input().split()))
    start = (inputs[0], inputs[1])
    end = (inputs[2], inputs[3])
    customers = []
    for i in range(n):
        customers.append((inputs[2*i+4], inputs[2*i+5]))
    least = float('inf')
    for i in range(n):
        for j in range(i+1, n):
            least = min(least, dist(customers[i], customers[j]))
        least = min(least, dist(customers[i], end))
    
    minimum = float('inf')
    visited = set()
    total = 0
    def backtracking(lst):
        global total, minimum

        if not lst:
            for i in range(n):
                total += dist(customers[i], start)
                lst.append(i)
                visited.add(i)
                backtracking(lst)
                visited.remove(i)
                lst.pop()
                total -= dist(customers[i], start)
        else:
            if len(visited) == n:
                minimum = min(minimum, total + dist(customers[lst[-1]], end))
            else:
                for i in range(n):
                    if i not in visited and total + least*(n+1 - len(visited)) < minimum:
                        total += dist(customers[lst[-1]], customers[i])
                        lst.append(i)
                        visited.add(i)
                        backtracking(lst)
                        visited.remove(i)
                        lst.pop()
                        total -= dist(customers[lst[-1]], customers[i])
    
    backtracking([])
    print(minimum)