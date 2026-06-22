STADIUMS = 3
MAX_GOALS = 10
PLAYERS = 5

goals = [[] for _ in range(STADIUMS)]
playerGoals = [0] * PLAYERS


def addGoalToStadium0(minute, playerID):
    goals[0].append(minute)
    playerGoals[playerID] += 1


def addGoalToStadium1(minute, playerID):
    goals[1].append(minute)
    playerGoals[playerID] += 1


def addGoalToStadium2(minute, playerID):
    if len(goals[2]) >= MAX_GOALS:
        print("Stadium 2 is full")
        return

    goals[2].append(minute)
    playerGoals[playerID] += 1


def totalGoals():
    total = 0
    for s in range(STADIUMS):
        total += len(goals[s])
    return total


def topScorer():
    maxG = playerGoals[0]
    winner = 0

    for p in range(PLAYERS):
        if playerGoals[p] > maxG:
            maxG = playerGoals[p]
            winner = p

    return winner


def displayStadium(stadium):
    for goal in goals[stadium]:
        print(goal, end=" ")


addGoalToStadium0(15, 1)
addGoalToStadium0(42, 2)

addGoalToStadium1(8, 2)
addGoalToStadium1(67, 3)

addGoalToStadium2(23, 2)
addGoalToStadium2(55, 1)
addGoalToStadium2(80, 2)

print("Total Goals:", totalGoals())
print("Top Scorer: Player", topScorer())

print("Stadium 0 goals:", end=" ")
displayStadium(0)
print()

print("Stadium 1 goals:", end=" ")
displayStadium(1)
print()

print("Stadium 2 goals:", end=" ")
displayStadium(2)
print()
