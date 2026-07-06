def cardgame(nums):
    left = 0
    right = len(nums) - 1
    player1_score = 0
    player2_score = 0

    for i in range(1, len(nums) + 1):
        if i % 2 == 0:
            player2_score += max(nums[left], nums[right])
            if nums[left] >= nums[right]:
                left += 1
            else:
                right -= 1
        else:
            player1_score += max(nums[left], nums[right])
            if nums[left] >= nums[right]:
                left += 1
            else:
                right -= 1

    return f"{player1_score} {player2_score}"