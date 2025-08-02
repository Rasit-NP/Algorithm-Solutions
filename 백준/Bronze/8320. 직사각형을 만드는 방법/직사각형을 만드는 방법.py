import sys, math

def count_cases(n):
    count = 0

    for i in range(1, int(math.sqrt(n)+1)):
        if n%i == 0:
            count += 1
    return count

n = int(sys.stdin.readline())

ans = 0
for i in range(1, n+1):
    ans += count_cases(i)

print(ans)