import sys

q = int(sys.stdin.readline())
for _ in range(q):
    m = int(sys.stdin.readline())
    time = 6; minute = 0
    minutes = 6
    while m >= 50:
        m -= 50
        minutes += 12
    time += minutes//60
    minute += minutes%60
    if time >= 24:
        print(-1)
    else:
        if minute < 10:
            minute = '0' + str(minute)
        if time < 10:
            time = '0' + str(time)
        print(f"{time}:{minute}")