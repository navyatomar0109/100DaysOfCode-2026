STADIUMS = 3
MAX_GOALS = 10
PLAYERS = 5

goals = [[] for _ in range(STADIUMS)]
playerGoals = [0] * PLAYERS

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
    maxG = max(playerGoals)
    return playerGoals.index(maxG)

def displayStadium(stadium):
    for goal in goals[stadium]:
        print(goal, end=" ")
    print()

# Example Data
goals[0] = [15, 42]
goals[1] = [8, 67]
goals[2] = [23, 55, 80]

playerGoals[1] = 1
playerGoals[2] = 3
playerGoals[3] = 1
playerGoals[4] = 2

print("Total Goals:", totalGoals())
print("Top Scorer: Player", topScorer())

print("Stadium 0 goals:", end=" ")
displayStadium(0)

print("Stadium 1 goals:", end=" ")
displayStadium(1)

print("Stadium 2 goals:", end=" ")
displayStadium(2)