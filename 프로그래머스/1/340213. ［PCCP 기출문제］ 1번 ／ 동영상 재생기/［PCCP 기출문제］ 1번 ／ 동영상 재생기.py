def solution(video_len, pos, op_start, op_end, commands):
    def change_sec(mm_ss):
        return int(mm_ss[:2])*60 + int(mm_ss[-2:])
    
    video_len = change_sec(video_len)
    pos = change_sec(pos)
    op_start = change_sec(op_start)
    op_end = change_sec(op_end)
    
    for command in commands:
        if op_start <= pos < op_end:
            pos = op_end
        if command == "prev":
            pos -= 10
            if pos < 0: pos = 0
        if command == 'next':
            pos += 10
            if pos > video_len:
                pos = video_len
    if op_start <= pos < op_end:
        pos = op_end
    m = pos//60; s = pos%60
    if m<10:
        m = '0'+str(m)
    if s<10:
        s = '0'+str(s)
    answer = f"{m}:{s}"
    return answer