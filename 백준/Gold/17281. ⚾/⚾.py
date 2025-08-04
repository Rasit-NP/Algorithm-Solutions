import sys
from itertools import permutations

n = int(sys.stdin.readline())
        
def full_game(n, player_order):

    def inning(inning_count, start):
        score_inning = 0
        out_count = 0
        base1, base2, base3 = 0, 0, 0         # 1루, 2루, 3루
        i = start
        hit_inning = player_hit[inning_count]
        while out_count<3:
            player = player_list[i]
            hit = hit_inning[player]

            if hit == 0:
                out_count += 1
            elif hit == 1:
                score_inning += base3
                base3, base2, base1 = base2, base1, 1
            elif hit == 2:
                score_inning += base2 + base3
                base3, base2, base1 = base1, 1, 0
            elif hit == 3:
                score_inning += base1 + base2 + base3
                base3, base2, base1 = 1, 0, 0
            elif hit == 4:
                score_inning += base1 + base2 + base3 + 1
                base3, base2, base1 = 0, 0, 0
            if i == 8:
                i = 0
            else:
                i += 1

        return score_inning, i
    
    score_total = 0
    player_list = player_order
    start = 0

    for i in range(n):
        result_inning = inning(i, start)
        score_total += result_inning[0]
        start = result_inning[1]
        if maximum - score_total >= 24 * (n-i-1):
            break

    return score_total

player_hit = []

for _ in range(n):
    player_hit.append(tuple(map(int, sys.stdin.readline().split())))

maximum = 0

for order in permutations(list(range(1, 9))):
    player_order = list(order[:3]) + [0] + list(order[3:])
    score = full_game(n, player_order)
    if score > maximum:
        maximum = score

print(maximum)