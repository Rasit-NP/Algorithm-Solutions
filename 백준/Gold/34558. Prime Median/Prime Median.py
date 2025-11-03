import sys

def init():
    global primes, cnt_prime
    primes = []
    cnt_prime = [0, 0]
    is_prime = [True]*(1000001)
    is_prime[0] = is_prime[1] = False
    cnt = 0
    for x in range(2, 1000001):
        if not is_prime[x]:
            cnt_prime.append(cnt)
            continue
        cnt += 1
        cnt_prime.append(cnt)
        primes.append(x)
        num = 2*x
        while num <= 1000000:
            is_prime[num] = False
            num += x
    cnt_prime.append(cnt)

def run(a, b):
    a -= 1
    ca = cnt_prime[a]; cb = cnt_prime[b]
    if not((cb-ca)&1):
        print(-1)
    else:
        idx = (cb+ca-1)//2
        print(primes[idx])

if __name__ == "__main__":
    init()
    n = int(sys.stdin.readline())
    for _ in range(n):
        a, b = map(int, sys.stdin.readline().split())
        run(a, b)