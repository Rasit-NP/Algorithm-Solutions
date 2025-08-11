import sys

n = int(sys.stdin.readline())

def func(n):
    if n == 3:
        stars = ['***',
                 '* *',
                 '***']
        return stars
    else:
        k = n//3
        before = func(k)
        stars = ['']*n
        for i in range(k):
            stars[i] += before[i]*3
            stars[k+i] += before[i] + ' '*k + before[i]
            stars[2*k + i] += before[i]*3
        
        return stars
    
print('\n'.join(func(n)))