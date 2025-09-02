import sys

change = {'A':3, 'B':2, 'C':1, 'D':2, 'E':3, 'F':3, 'G':2, 'H':3, 'I':3, 'J':2, 'K':2,
          'L':1, 'M':2, 'N':2, 'O':1, 'P':2, 'Q':2, 'R':2, 'S':1, 'T':2, 'U':1, 'V':1,
          'W':1, 'X':2, 'Y':2, 'Z':1}

list1 = list(sys.stdin.readline().rstrip())
list2 = list(sys.stdin.readline().rstrip())
length = len(list1)
ans = []
for i in range(length):
    ans.append(change[list1[i]])
    ans.append(change[list2[i]])

while len(ans) > 2:
    new = []
    for i in range(len(ans)-1):
        new.append((ans[i]+ans[i+1])%10)
    ans = new

print(''.join(map(str, ans)))