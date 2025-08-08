t = int(input())

for tc in range(1, t+1):

    def comparison(str1, str2):
        num = {'ZRO': 0,
               'ONE': 1,
               'TWO': 2,
               'THR': 3,
               'FOR': 4,
               'FIV': 5,
               'SIX': 6,
               'SVN': 7,
               'EGT': 8,
               'NIN': 9}

        if num[str1] <= num[str2]:   return True
        else:   return False

    n = int(input().split()[1])

    lst = input().rstrip().split()

    for i in range(n-1):
        for j in range(n-1-i):
            if comparison(lst[j],lst[j+1]):
                continue
            else:
                lst[j], lst[j+1] = lst[j+1], lst[j]

    print(f'#{tc}', end='\n')
    print(' '.join(lst))