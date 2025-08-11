import sys

n = int(sys.stdin.readline())

def func(n):
    if n == 3:
        stars = ['  *  ',
                 ' * * ',
                 '*****']
        return stars
    else:
        k = n//2
        stars = [''] * n
        before = func(k)
        for i in range(k):
            stars[i] += ' ' * k + before[i%k] + ' ' * k
        for i in range(k,2*k):
            stars[i] +=before[i%k] + ' ' + before[i%k]
        return stars

print('\n'.join(func(n)))