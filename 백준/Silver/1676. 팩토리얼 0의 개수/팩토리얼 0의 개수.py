n = int(input())

five5 = set()
five25 = set()
five125 = set()

for i in range(1, n+1):
    if i % 125 == 0:
        five125.add(i)
    elif i % 25 == 0:
        five25.add(i)
    elif i % 5 == 0:
        five5.add(i)

print(3*len(five125)+2*len(five25)+len(five5))