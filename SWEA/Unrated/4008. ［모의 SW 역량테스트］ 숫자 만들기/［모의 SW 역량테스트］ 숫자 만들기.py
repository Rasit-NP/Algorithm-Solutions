import copy
t = int(input())
 
for tc in range(1, t+1):
    n = int(input())
 
    operators = list(map(int, input().split()))
    numbers = list(map(int, input().split()))
    lst = []
 
    maximum = -float('inf')
    minimum = float('inf')
    def makelist(lst, operators):
        global maximum
        global minimum
        def calculate(lst, numbers):
            nums = copy.deepcopy(numbers)
            for i in range(n-1):
                if lst[i] == '+':
                    nums[i+1] = nums[i] + nums[i+1]
                elif lst[i] == '-':
                    nums[i+1] = nums[i] - nums[i+1]
                elif lst[i] == '*':
                    nums[i+1] = nums[i] * nums[i+1]
                elif lst[i] == '/':
                    nums[i+1] = int(nums[i] / nums[i+1])
            return nums[-1]
 
        if len(lst) == n-1:
            final = calculate(lst, numbers)
            maximum = max(maximum, final)
            minimum = min(minimum, final)
        else:
            for i in range(4):
                if operators[i] > 0:                    
                    if i == 0:
                        lst.append('+')
                        operators[i] -= 1
                        makelist(lst, operators)
                        operators[i] += 1
                        lst.pop()
                    elif i == 1:
                        lst.append('-')
                        operators[i] -= 1
                        makelist(lst, operators)
                        operators[i] += 1
                        lst.pop()
                    elif i == 2:
                        lst.append('*')
                        operators[i] -= 1
                        makelist(lst, operators)
                        operators[i] += 1
                        lst.pop()
                    elif i == 3:
                        lst.append('/')
                        operators[i] -= 1
                        makelist(lst, operators)
                        operators[i] += 1
                        lst.pop()
     
    makelist(lst, operators)
 
    print(f'#{tc}', maximum-minimum)