def check(code):
    table = {(3, 2, 1, 1): 0, (2, 2, 2, 1): 1, (2, 1, 2, 2): 2, (1, 4, 1, 1): 3, (1, 1, 3, 2): 4,
            (1, 2, 3, 1): 5, (1, 1, 1, 4): 6, (1, 3, 1, 2): 7, (1, 2, 1, 3): 8, (3, 1, 1, 2): 9}
    length = len(code)
    each = length // 8      # each칸이 한 글자
    nums = [None]*8
    ans = []
    for i in range(8):
        nums[i] = code[i*each:(i+1)*each]
    d = each // 7
    for num in nums:
        now = num[0]
        stack = 0
        i == 0
        change = []
        for i in range(0, each, d):
            if num[i] == now:
                stack += 1
            else:
                change.append(stack)
                now = num[i]
                stack = 1
            i += d
        change.append(stack)
        ans.append(table[tuple(change)])

    if ((ans[0]+ans[2]+ans[4]+ans[6])*3 + (ans[1]+ans[3]+ans[5]) + ans[7])%10 == 0:
        return sum(ans)
    else:
        return False

def change(ox_num):
    table = {'0': '0000', '1': '0001', '2': '0010', '3': '0011',
             '4': '0100', '5': '0101', '6': '0110', '7': '0111',
             '8': '1000', '9': '1001', 'A': '1010', 'B': '1011',
             'C': '1100', 'D': '1101', 'E': '1110', 'F': '1111'}
    ans = ''
    for i in ox_num:
        ans += table[i]
    return ans

def sibal(letter):
    changed = change(letter)
    long = len(changed)
    size = 1
    while 56*size < long or abs(long-size*56) <= 7*size:
        size += 1
    size -= 1
    diff = long - size*56
    state = False
    if diff == 0:
        for k in range(3*(size+1)):
            if changed[:k] == '0'*k:
                try:
                    check(changed[k:]+'0'*k)
                    state = True
                    break
                except:
                    pass
            if changed[-k:] == '0'*k:
                try:
                    check('0'*k + changed[:long-k])
                    state = True
                    break
                except:
                    pass

    elif diff < 0:
        for k in range(abs(diff)+1):
            try:
                check('0'*k+changed+'0'*(abs(diff)-k))
                state = True
                break
            except:
                continue
    else:
        for k in range(diff+1):
            if changed[:k] == '0'*k and changed[-(diff-k):] == '0'*(diff-k):
                try:
                    check(changed[k:-(diff-k)])
                    state = True
                    break
                except:
                    continue
    return state

t = int(input())
for tc in range(1, t+1):
    print(f'#{tc}', end=' ')
    count = 0
    n, m = map(int, input().split())
    board = [list(input().rstrip()) for _ in range(n)]
    visited = [[False for _ in range(m)] for _ in range(n)]
    total = 0
    for i in range(n):
        for j in range(m):
            if board[i][j] == '0' and not visited[i][j]:
                visited[i][j] = True
            elif not visited[i][j]:
                ans = 0
                x, y = i, j
                for dx in range(n):
                    if x+dx>=n or (board[x+dx][y] == '0'):
                        break
                    if dx > 0:
                        for dy in range(length):
                            if y+dy<m and visited[x][y+dy]:
                                visited[x+dx][y+dy] = True
                        continue
                    for dy in range(n):
                        k = 0
                        if y+dy<m:
                            if visited[x+dx][y+dy]:
                                length = dy
                                break
                            if board[x+dx][y+dy] != '0':
                                visited[x+dx][y+dy] = True
                            else:
                                if not sibal(''.join(board[x+dx][y:y+dy])):
                                    visited[x+dx][y+dy] = True
                                else:
                                    length = dy
                                    break
                        else:
                            length = dy
                            break
                    letter = ''.join(board[x][y:y+length])
                    changed = change(letter)
                    long = len(changed)
                    size = 1
                    while 56*size < long or abs(long-size*56) <= 7*size:
                        size += 1
                    size -= 1
                    diff = long - size*56
                    if diff == 0:
                        for k in range(3*(size+1)):
                            if changed[:k] == '0'*k:
                                try:
                                    ans = check(changed[k:]+'0'*k)
                                    break
                                except:
                                    pass
                            if changed[-k:] == '0'*k:
                                try:
                                    ans = check('0'*k + changed[:long-k])
                                    break
                                except:
                                    pass

                    elif diff < 0:
                        for k in range(abs(diff)+1):
                            try:
                                ans = check('0'*k+changed+'0'*(abs(diff)-k))
                                break
                            except:
                                continue
                    else:
                        for k in range(diff+1):
                            if changed[:k] == '0'*k and changed[-(diff-k):] == '0'*(diff-k):
                                try:
                                    ans = check(changed[k:-(diff-k)])
                                    break
                                except:
                                    continue
                    if ans:
                        total += ans

    print(total)