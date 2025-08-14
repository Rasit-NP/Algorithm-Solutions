import sys

lst = list(sys.stdin.readline().rstrip())
stack = []
ans = ''
operators = '+-*/()'
priority = {'+':(1, 1),
            '-':(1, 1),
            '*':(2, 2),
            '/':(2, 2),
            '(':(0, 3),
}

for letter in lst:
    if letter in operators:
        if letter == ')':
            while True:
                operator = stack.pop()
                if operator == '(':
                    break
                else:
                    ans += operator
        else:
            if len(stack) == 0:
                stack.append(letter)
            elif priority[letter][1] > priority[stack[-1]][0]:
                stack.append(letter)
            else:
                while stack and priority[letter][1] <= priority[stack[-1]][0]:
                    operator = stack.pop()
                    ans += operator
                stack.append(letter)
            
    else:
        ans += letter

while stack:
    operator = stack.pop()
    if operator == '(':
        continue
    else:
        ans += operator

print(ans)