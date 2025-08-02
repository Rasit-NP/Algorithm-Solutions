import sys

lst = []

for _ in range(10):
    num = int(sys.stdin.readline())
    lst.append(num%42)

print(len(set(lst)))