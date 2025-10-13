import sys

n = int(sys.stdin.readline())
total = []
nums = list(map(int, sys.stdin.readline().split()))

def cmp(a_tup, b_tup):
    a, a_digit, a_cap = a_tup
    b, b_digit, b_cap = b_tup
    a_scale = 10 ** (a_digit - 1)
    b_scale = 10 ** (b_digit - 1)
    a_com = []; b_com = []

    if b == 0:
        return True
    if a == 0:
        return False
    if a_digit == b_digit:
        return a >= b

    if a_cap > b_cap:
        return True
    elif a_cap < b_cap:
        return False
    x = a
    y = b
    while a_scale > 0:
        a_com.append(x//a_scale)
        x %= a_scale
        a_scale //= 10
    while b_scale > 0:
        b_com.append(y//b_scale)
        y %= b_scale
        b_scale //= 10
    for i in range(2 * max(a_digit, b_digit)):
        a_i, b_i = i%a_digit, i%b_digit
        if a_com[a_i] > b_com[b_i]:
            return True
        if b_com[b_i] > a_com[a_i]:
            return False
    return a >= b

for i in range(n):
    x = nums[i]
    digit = 0
    cap = 0
    while x > 0:
        if x < 10:
            cap = x
        x //= 10
        digit += 1
    total.append((nums[i], digit, cap))

for i in range(n-1, 0, -1):
    for j in range(i):
        if cmp(total[j], total[j+1]):
            continue
        else:
            total[j], total[j+1] = total[j+1], total[j]



if total[0][0] == 0:
    print(0)
else:
    for i in range(n):
        sys.stdout.write(str(total[i][0]))