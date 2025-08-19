import sys

n, m = map(int, sys.stdin.readline().split())

words = []
count = 0

for _ in range(n):
    inputs = sys.stdin.readline().rstrip()
    words.append(inputs)
words.sort()

def find(words, post):
    left = 0
    right = n
    length = len(post)
    if words[left][:length] == post:
        return True
    while right-left > 1:
        mid = (left+right)//2
        word = words[mid][:length]
        if word > post:
            right = mid
        elif word < post:
            left = mid
        elif word == post:
            return True
    return False

count = 0
for _ in range(m):
    inputs = sys.stdin.readline().rstrip()
    if find(words, inputs):
        count += 1

print(count)