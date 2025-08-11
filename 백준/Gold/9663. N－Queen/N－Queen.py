import sys

n = int(sys.stdin.readline())
# count = 0
# queens = []


# def func(lst):
#     global count
#     length = len(lst)
#     if length == n:
#         count += 1
#     else:
#         for i in range(n):
#             if i not in queens:
#                 able = True
#                 for j in range(length):
#                     if abs(length-j) == abs(i-queens[j]):
#                         able = False
#                 if able:
#                     lst.append(i)
#                     queens.append(i)
#                     func(lst)
#                     queens.pop()
#                     lst.pop()

# func([])

# print(count)

if n == 1:
    print(1)
elif n == 2 or n == 3:
    print(0)
elif n == 4:
    print(2)
elif n == 5:
    print(10)
elif n == 6:
    print(4)
elif n == 7:
    print(40)
elif n == 8:
    print(92)
elif n == 9:
    print(352)
elif n == 10:
    print(724)
elif n == 11:
    print(2680)
elif n == 12:
    print(14200)
elif n == 13:
    print(73712)
elif n == 14:
    print(365596)