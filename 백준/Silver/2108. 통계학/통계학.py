import sys
from collections import Counter

n = int(sys.stdin.readline())
ints = []
for _ in range(n):
    ints.append(int(sys.stdin.readline()))
ints.sort()

dic = Counter(ints)
many_freq = []

mean = round(sum(ints)/len(ints))
mid = ints[len(ints)//2]

max_freq = max(dic.values())
for i in ints:
    if dic[i] == max_freq:
        many_freq.append(i)
many_freq = list(set(many_freq))
many_freq.sort()
if len(many_freq) == 1: freq = many_freq[0]
else:   freq = many_freq[1]
    
term = max(ints) - min(ints)

print(mean)
print(mid)
print(freq)
print(term)