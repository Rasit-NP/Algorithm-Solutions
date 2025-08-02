import sys

def n_letter_delete(n, lst):
    global letter_count
    letter_count += 1
    return lst[n:]

inputs = list(sys.stdin.readline().rstrip())
letter_count = 0
while True:
    left = inputs[0]

    if left == 'c':
        if len(inputs)>=2 and (inputs[1] == '=' or inputs[1] == '-'):
            inputs = n_letter_delete(2, inputs)
        else:
            inputs = n_letter_delete(1, inputs)
    elif left == 'd':
        if len(inputs)>=3 and inputs[1] == 'z' and inputs[2] == '=':
            inputs = n_letter_delete(3, inputs)
        elif len(inputs)>=2 and inputs[1] == '-':
            inputs = n_letter_delete(2, inputs)
        else:
            inputs = n_letter_delete(1, inputs)
    elif left == 'l':
        if len(inputs)>=2 and inputs[1] == 'j':
            inputs = n_letter_delete(2, inputs)
        else:
            inputs = n_letter_delete(1, inputs)
    elif left == 'n':
        if len(inputs)>=2 and inputs[1] == 'j':
            inputs = n_letter_delete(2, inputs)
        else:
            inputs = n_letter_delete(1, inputs)
    elif left == 's':
        if len(inputs)>=2 and inputs[1] == '=':
            inputs = n_letter_delete(2, inputs)
        else:
            inputs = n_letter_delete(1, inputs)
    elif left == 'z':
        if len(inputs)>=2 and inputs[1] == '=':
            inputs = n_letter_delete(2, inputs)
        else:
            inputs = n_letter_delete(1, inputs)
    else:
        inputs = n_letter_delete(1, inputs)
    
    if len(inputs) == 0:
        break

print(letter_count)