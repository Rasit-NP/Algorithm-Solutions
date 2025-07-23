nums = list(map(int, input().split()))

square = lambda a: a**2

ans = list(map(square, nums))

print(sum(ans)%10)