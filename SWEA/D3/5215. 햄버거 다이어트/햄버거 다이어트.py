t = int(input())

for tc in range(1, t+1):
    n, limit = map(int, input().split())
    scores = []
    calories = []
    for _ in range(n):
        score, calory = map(int, input().split())
        scores.append(score)
        calories.append(calory)
    ate = sum(calories)
    total = sum(scores)
    if ate <= limit:
        print(f'#{tc} {total}')
    else:
        minimum = float('inf')
        over = ate-limit
        lst = []

        def backtracking(lst, sum_score, sum_cal):
            global minimum
            if sum_cal >= over:
                minimum = min(minimum, sum_score)
            elif sum_score < minimum and sum_cal < over:
                for i in range(n):
                    if i not in lst:
                        sum_score += scores[i]
                        sum_cal += calories[i]
                        lst += [i]
                        backtracking(lst, sum_score, sum_cal)
                        lst.pop()
                        sum_cal -= calories[i]
                        sum_score -= scores[i]

        backtracking(lst, 0, 0)

        print(f'#{tc} {total-minimum}')