import sys

def test(t, lst):
    i = 0
    di = 0
    sums = 0
    ans = []
    while i + di < n:
        sums += lst[i+di]
        if sums > t:
            if di == 0:
                return False
            else:
                ans.append(di)
                i += di
                di = 0
                sums = 0
                if len(ans) == m and i < n:
                    return False
        elif sums == t:
            ans.append(di+1)
            i += di+1
            di = 0
            sums = 0
            if len(ans) == m and i < n:
                return False
        elif sums < t:
            di += 1
    if sums:
        ans.append(di)
    return ans

n, m = map(int, sys.stdin.readline().split())

nums = list(map(int, sys.stdin.readline().split()))
sums = sum(nums)
left = 0
right = sums

while right - left > 1:
    mid = (left+right)//2
    ans = test(mid, nums)
    if ans:
        right = mid
    else:
        left = mid
ans = test(right, nums)
real = []
less = m-len(ans)
if less > 0:
    for i in ans:
        if i == 1:
            real.append(i)
        else:
            while less > 0 and i > 1:
                real.append(1)
                i -= 1
                less -= 1
            real.append(i)
else:
    real = ans


print(right)
print(' '.join(map(str, real)))