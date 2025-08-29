import sys

def input():
    result = int(sys.stdin.readline())
    m, n = map(int, sys.stdin.readline().split())
    first = [int(sys.stdin.readline()) for _ in range(m)] * 2
    second = [int(sys.stdin.readline()) for _ in range(n)] * 2
    
    return result, m, n, first, second


result, m, n, first, second = input()

part_first = {0:1}
part_second = {0:1}
ans = 0
for i in range(m):
    sum = first[i]
    if sum in part_first:
        part_first[sum] += 1
    else:
        part_first[sum] = 1
    for j in range(1, m):
        sum += first[i+j]
        if sum in part_first:
            if j == m-1:
                break
            part_first[sum] += 1
        else:
            part_first[sum] = 1

for i in range(n):
    sum = second[i]
    if sum in part_second:
        part_second[sum] += 1
    else:
        part_second[sum] = 1
    for j in range(1, n):
        sum += second[i+j]
        if sum in part_second:
            if j == n-1:
                break
            part_second[sum] += 1
        else:
            part_second[sum] = 1

for component_first in part_first:
    target = result - component_first
    if target in part_second:
        ans += part_first[component_first] * part_second[target]

print(ans)