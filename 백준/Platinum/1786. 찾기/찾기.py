import sys

def init():
    global t, p, len_t, len_p
    t = sys.stdin.readline().rstrip()
    p = sys.stdin.readline().rstrip()
    len_t = len(t)
    len_p = len(p)

def find_lps(p):
    lps = [0]*len_p
    length = 0
    i = 1
    
    while i < len_p:
        if p[i] == p[length]:
            length += 1
            lps[i] = length
            i += 1
        else:
            if length != 0:
                length = lps[length - 1]
            else:
                lps[i] = 0
                i += 1
    return lps

def run(t, p):
    lps = find_lps(p)
    i = j = 0
    ans = []

    while i<len_t:
        if t[i] == p[j]:
            i += 1
            j += 1
        
        if j == len_p:
            ans.append(i-j+1)
            j = lps[j-1]
        elif i<len_t and t[i] != p[j]:
            if j != 0:
                j = lps[j-1]
            else:
                i += 1
    return ans

if __name__ == "__main__":
    init()
    ans = run(t, p)
    print(len(ans))
    print(' '.join(map(str, ans)))