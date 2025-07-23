import sys

def calculateTime(targetHeight, block):
    sumTime = 0
    for i in height:
        if targetHeight > i:    #쌓기
            sumTime += (targetHeight-i)*heightCount[i]
            block -= (targetHeight-i)*heightCount[i]
        elif targetHeight < i:  #버리기
            sumTime += 2 * (i-targetHeight)*heightCount[i]
            block += (i-targetHeight)*heightCount[i]
    if block < 0:   return([float('inf'),0])
    else:       return([sumTime, targetHeight])

n, m, b = map(int, sys.stdin.readline().split())
heightCount = {}

for _ in range(n):
    inputs = list(map(int, sys.stdin.readline().split()))
    for i in range(m):
        if inputs[i] in heightCount:
            heightCount[inputs[i]] += 1
        else:
            heightCount[inputs[i]] = 1

height = list(heightCount.keys())
minTime = float('inf')
maxHeight = 0

for i in range(min(height), max(height)+1):
    TimeI = calculateTime(i, b)[0]
    HeightI = calculateTime(i, b)[1]
    if TimeI < minTime:
        minTime = TimeI
        maxHeight = HeightI
    elif TimeI == minTime:
        if HeightI > maxHeight:
            maxHeight = HeightI

print(f'{minTime} {maxHeight}')