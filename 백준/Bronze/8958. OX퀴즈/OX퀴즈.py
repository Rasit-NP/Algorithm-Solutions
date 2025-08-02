import sys

t = int(sys.stdin.readline())

for _ in range(t):
    inputs = sys.stdin.readline().rstrip().split('X')
    score = 0
    for combo in inputs:
        score += (len(combo)*(len(combo)+1))//2
    
    print(score)