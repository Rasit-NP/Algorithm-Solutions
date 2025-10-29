import sys

check = [1 for _ in range(384)]
check[0], check[1] = 0, 0
primes = []
for i in range(2, 384):
    if not check[i]:
        continue
    x = i
    while (x<=383):
        if check[x]:
            check[x] = 0
        x += i
    primes.append(i)

s, e, k = map(int, sys.stdin.readline().split())
data = [1 for _ in range(e-s+1)]
ans = 0
cnt = 0
for prime in primes:
    if cnt == k:
        break
    for i in range(s, max(e+1, prime+1)):
        if not data[i-s]:
            continue
        if not i%prime:
            data[i-s] = 0
            ans += prime
            cnt += 1
            if cnt == k:
                break
print(ans)