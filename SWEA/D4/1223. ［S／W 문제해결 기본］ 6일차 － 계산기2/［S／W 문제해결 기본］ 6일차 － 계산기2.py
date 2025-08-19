t = 10

for tc in range(1, t+1):
    length = int(input())
    inputs = list(input().rstrip())
    operators = ('+', '*')
    stack = []
    transform = ''
    for i in range(len(inputs)):
        data = inputs[i]
        if data in operators:
            if stack:
                if data == '*':
                    while stack[-1] == '*':
                        a = stack.pop()
                        transform += a
                        if len(stack) == 0:
                            break
                    stack.append(data)
                else:
                    while stack:
                        a = stack.pop()
                        transform += a
                    stack.append(data)
            else:
                stack.append(data)

        else:
            transform += data
    if stack:
        while stack:
            a = stack.pop()
            transform += a
    
    stack = []
    for letter in transform:
        if letter not in operators:
            stack.append(letter)
        else:
            a = int(stack.pop())
            b = int(stack.pop())
            if letter == '+':
                stack.append(a + b)
            elif letter == '*':
                stack.append(a * b)
            


    print(f'#{tc}', end=' ')
    print(stack[0])