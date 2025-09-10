import sys

while True:
    d, m, y = map(int, sys.stdin.readline().split())
    if y+m+d == 0:
        break
    days = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30,
            7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
    
    ans = 0
    for i in range(1, m):
        ans += days[i]
        if i == 2:
            if not y%4 and (not y%400 or y%100):
                ans += 1
    
    print(ans+d)