import sys

n = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))

ans = []
pos = [None for _ in range(n)]

for i in range(n):
    num = lst[i]
    if ans:
        length = len(ans)
        if num > ans[-1]:
            pos[i] = length
            ans.append(num)
            continue
        left, right = -1, length
        while right-left>1:
            mid = (right+left)//2
            if ans[mid] > num:
                right = mid
            else:
                left = mid
        pos[i] = right
        ans[right] = num
    else:
        ans.append(num)
        pos[i] = [0]

print(len(ans))