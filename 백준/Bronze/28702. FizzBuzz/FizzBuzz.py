a = input()
b = input()
c = input()

def output(t):
    if t%3 == 0 and t%5 == 0:
        print('FizzBuzz')
    elif t%3 == 0:
        print('Fizz')
    elif t%5 == 0:
        print('Buzz')
    else:
        print(t)

lis = ['Fizz', 'Buzz', 'FizzBuzz']
if a not in lis:
    output(int(a)+3)
elif b not in lis:
    output(int(b)+2)
elif c not in lis:
    output(int(c)+1)