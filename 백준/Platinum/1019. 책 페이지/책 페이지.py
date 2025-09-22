import sys

n = int(sys.stdin.readline())

count = [0 for _ in range(10)]

digit = 1
while digit <= n:
    if digit > 1:
        compare = (n//digit)%10
    elif digit == 1:
        compare = n % 10
    for i in range(10):
        count[i] += (n // (digit*10)) * digit
        if i == 0:
            if digit*10 > n:
                continue
            else:
                if compare == 0:
                    count[i] += (n%digit) + 1
                else:
                    count[i] += digit
        elif 0 < i < compare:
            count[i] += digit
        elif i == compare:
            count[i] += (n%digit) + 1
    count[0] -= digit//10
    digit *= 10

sys.stdout.write(' '.join(map(str, count))+'\n')