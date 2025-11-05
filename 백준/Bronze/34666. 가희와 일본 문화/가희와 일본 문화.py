import sys

q = int(sys.stdin.readline())
maximum = [100, 100, 90, 95, 90, 80]
for _ in range(q):
    test, a, b, c = map(int, sys.stdin.readline().split())
    score = (a, b, c)
    check = 0
    if test<=2 and score[2]>=50:
        if max(score[0], score[1])*3 < maximum[test]:
            check = 1
        if score[0]<22 or score[1]<22:
            check = 1
    if check:
        print("YES")
    else:
        print("NO")