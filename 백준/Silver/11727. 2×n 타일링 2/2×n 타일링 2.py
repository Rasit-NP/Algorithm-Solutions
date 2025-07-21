n = int(input())

fac = [1]*(n+1)
for i in range(n):
    fac[i+1] = fac[i]*(i+1)


sum = 0
for i in range(n//2+1):
    for j in range(i+1):
        sum += fac[n-2*i+i]//(fac[n-2*i]*fac[j]*fac[i-j])

print(sum%10007)