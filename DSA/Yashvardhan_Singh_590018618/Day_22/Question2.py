cards = [4, 1, 2, 10]

left = 0
right = len(cards) - 1

player1 = 0
player2 = 0
turn = 0

while left <= right:
    if cards[left] >= cards[right]:
        picked = cards[left]
        left += 1
    else:
        picked = cards[right]
        right -= 1

    if turn % 2 == 0:
        player1 += picked
    else:
        player2 += picked

    turn += 1

print(player1, player2)