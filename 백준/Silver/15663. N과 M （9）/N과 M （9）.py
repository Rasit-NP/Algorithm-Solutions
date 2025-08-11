import sys
sys.setrecursionlimit(10**6)

n, m = map(int, sys.stdin.readline().split())
nums = list(map(int, list(sys.stdin.readline().split())))
nums.sort()
count = {}

for num in nums:
    if num in count:
        count[num] += 1
    else:
        count[num] = 1

def backtracking(lst):
    length = len(lst)
    if length == m:
        sys.stdout.write(' '.join(list(map(str, lst)))+'\n')
    else:
        for key in count:
            if count[key] > 0:
                lst.append(key)
                count[key] -= 1
                backtracking(lst)
                count[key] += 1
                lst.pop()

backtracking([])