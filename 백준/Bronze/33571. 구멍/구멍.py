import sys

change = {'A':1, 'B':2, 'D':1, 'O':1, 'P':1, 'Q':1, 'R':1,
          'a':1, 'b':1, 'd':1, 'e':1, 'g':1, 'o':1, 'p':1, 'q':1,
          '@':1}

inputs = list(sys.stdin.readline().rstrip())
count = 0
for letter in inputs:
    if letter not in change:
        continue
    else:
        count += change[letter]

print(count)