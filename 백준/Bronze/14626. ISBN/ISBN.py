import sys

num = list(input())
check = [1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1]
sum = 0

for i in range(13):
    if num[i] == '*':
        index_star = i
    else:
        sum += int(num[i])*check[i]

for i in range(10):
    if (i*check[index_star]+sum)%10 == 0:
        print(i)
        break