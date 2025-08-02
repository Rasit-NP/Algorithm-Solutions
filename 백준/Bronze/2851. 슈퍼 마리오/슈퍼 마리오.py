import sys

inputs = list(map(int, sys.stdin.readlines()))
score = 0


for mushroom in inputs:
    if abs(100 - score) >= abs(100 - (score + mushroom)):
        score += mushroom
    else:
        break

print(score)