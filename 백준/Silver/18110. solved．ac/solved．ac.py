import sys

def realround(a):
    if (a - float(int(a))) * 2 < 1:
        return int(a)
    else:
        return int(a) + 1


n = int(sys.stdin.readline())
opinions = [0] * n

for i in range(n):
    opinions[i] = int(sys.stdin.readline())

opinions.sort()

cut = realround(len(opinions)*0.15)

data = opinions[cut:len(opinions)-cut]

if n == 0:
    print(0)
else:
    print(realround(sum(data)/len(data)))