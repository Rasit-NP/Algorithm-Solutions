import sys

def count(num, lst):
    ans = 0
    now = 0
    for i in range(len(lst)):
        if lst[i] > now:
            now = num
            ans += 1
        now -= lst[i]
    return ans

n, m = map(int, sys.stdin.readline().split())

lst = []
for _ in range(n):
    lst.append(int(sys.stdin.readline()))

left = max(lst)-1
right = sum(lst)

while right-left > 1:
    test = (left+right)//2
    t = count(test, lst)
    if t > m:
        left = test
    else:
        right = test
    

print(right)