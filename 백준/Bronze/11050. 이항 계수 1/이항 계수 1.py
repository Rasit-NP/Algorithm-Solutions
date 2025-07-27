n, k = map(int, input().split())
factorial = {0: 1}

prod = 1
for i in range(n):
    if i+1 == k or i+1 == n-k or i+1 == n:
        prod *= (i+1)
        factorial[i+1] = prod
    else:
        prod *= (i+1)

print(factorial[n]//(factorial[k]*factorial[n-k]))