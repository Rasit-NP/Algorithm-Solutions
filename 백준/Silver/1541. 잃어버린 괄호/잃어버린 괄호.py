input = input().rstrip().split('-')

for i in range(len(input)):
    input[i] = sum(list(map(int, input[i].split('+'))))

print(input[0]-sum(input[1:]))