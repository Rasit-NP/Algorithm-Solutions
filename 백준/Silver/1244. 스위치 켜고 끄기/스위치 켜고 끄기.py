import sys

def switch_change(switches, index):
    if switches[index] == 1:
        switches[index] = 0
    else:
        switches[index] = 1

n = int(sys.stdin.readline())
switches = [None] + list(map(int,sys.stdin.readline().split()))
population = int(sys.stdin.readline())

for _ in range(population):
    gen, num = map(int, sys.stdin.readline().split())
    if gen == 1:
        i = 1
        while num*i <= len(switches)-1:
            switch_change(switches, num*i)
            i += 1
    elif gen == 2:
        switch_change(switches, num)
        d = 1
        while num + d <= len(switches)-1 and num - d >= 1 and switches[num+d] == switches[num-d]:
            switch_change(switches, num+d)
            switch_change(switches, num-d)
            d += 1

switches = switches[1:]

for i in range(len(switches)):
    if i%20 == 19:
        print(switches[i])
    else: print(switches[i], end=' ')