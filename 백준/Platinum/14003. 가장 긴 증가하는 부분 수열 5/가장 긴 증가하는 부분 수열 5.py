import sys

n = int(sys.stdin.readline())
nums = list(map(int, sys.stdin.readline().split()))

tail = []
prev = []
tail_idx = []

for i in range(n):
    num = nums[i]
    length = len(tail)
    if length == 0:
        tail.append(num)
        prev.append(None)
        tail_idx.append(0)
    elif num > tail[-1]:
        prev.append(tail_idx[-1])
        tail_idx.append(i)
        tail.append(num)
    else:
        left = -1
        right = length
        while right - left > 1:
            mid = (left+right)//2
            if tail[mid] >= num:
                right = mid
            else:
                left = mid
        idx = right
        tail[idx] = num
        if idx == 0:
            prev.append(None)
        else:
            prev.append(tail_idx[idx-1])
        tail_idx[idx] = i

idx = tail_idx[-1]
ans = []

while idx is not None:
    ans.append(nums[idx])
    idx = prev[idx]

sys.stdout.write(f'{len(ans)}\n')
sys.stdout.write(' '.join(map(str, ans[::-1])))