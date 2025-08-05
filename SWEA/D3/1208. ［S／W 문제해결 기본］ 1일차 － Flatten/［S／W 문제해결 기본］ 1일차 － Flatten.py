for tc in range(1, 11):
    n = int(input())
    boxes = list(map(int, input().split()))
    temp = [0]*101
    for i in boxes:
        temp[i] += 1
    
    num = 0
    change_box = 0
    for i in range(1, 101):
        if change_box + num > n:
            min_height = i-1
            break
        change_box += num
        num += temp[i]
    
    num = 0
    change_box = 0
    for i in range(100,0,-1):
        if change_box + num > n:
            max_height = i+1
            break
        change_box += num
        num += temp[i]

    if max_height > min_height:
        print(f'#{tc}', max_height-min_height)
    else:
        if sum(boxes)%len(boxes) == 0:
            print(f'#{tc}', 0)
        else:
            print(f'#{tc}', 1)