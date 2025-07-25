import sys

def dfs(n):
    if n in meetingBranch:
        for i in meetingBranch[n]:
            if not knowTrue[i]:
                knowTrue[i] = True
                dfs(i)

n, m = map(int, sys.stdin.readline().split())
meetingBranch = {}
party = []
truePerson = list(map(int, sys.stdin.readline().split()))[1:]

for k in range(m):
    partyPeople = list(map(int, sys.stdin.readline().split()))
    party.append(partyPeople[1:])
    for i in party[k]:
        for j in party[k]:
            if i != j:
                if i not in meetingBranch:
                    meetingBranch[i] = [j]
                else:
                    meetingBranch[i].append(j)

knowTrue = [False]*(n+1)

for i in truePerson:
    if knowTrue[i] == False:
        knowTrue[i] = True
        dfs(i)

count = 0

for eachParty in party:
    for i in eachParty:
        if knowTrue[i]:
            count += 1
            break

print(m-count)