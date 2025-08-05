nums = list(map(int, input().split()))
 
temp = [0] * (1000000+1)
 
for i in nums:
    temp[i] += 1
 
for i in range(1, len(temp)-1):
    temp[i+1] += temp[i]
 
for i in range(1, 1000000+1):
    if temp[i] >= 500001:
        print(i)
        break