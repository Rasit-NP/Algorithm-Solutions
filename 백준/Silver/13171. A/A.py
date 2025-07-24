import sys

a = int(sys.stdin.readline())
x = int(sys.stdin.readline())
twos = []
exps = [a%1000000007]
## x를 2진수로 표현하기
while x:
    twos.append(x%2)
    x //= 2

ans = 1
for i in range(len(twos)):
    if not i == 1:
        exps.append((exps[i-1]**2)%1000000007)
    if not twos[i] == 0:
        ans = (ans*twos[i]*exps[i])%1000000007

print(ans)