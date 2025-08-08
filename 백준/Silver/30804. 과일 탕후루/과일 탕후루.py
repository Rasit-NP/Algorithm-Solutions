import sys

def check(dict):
    count = 0
    for key in dict.keys():
        if dict[key] != 0:
            count += 1
    return count

n = int(sys.stdin.readline())
lst = list(map(int, sys.stdin.readline().split()))

left, right = 0, 1
maximum = 0
fruits = {1:0,
          2:0,
          3:0,
          4:0,
          5:0,
          6:0,
          7:0,
          8:0,
          9:0}

fruits[lst[left]] += 1

while left < n-1:
    if check(fruits) <= 2:
        maximum = max(maximum, right-left)
        if right == n:
            break
        else:
            fruits[lst[right]] += 1
            right += 1
    else:
        fruits[lst[left]] -= 1
        left += 1
if n == 1:
    print(1)
else:
    print(maximum)