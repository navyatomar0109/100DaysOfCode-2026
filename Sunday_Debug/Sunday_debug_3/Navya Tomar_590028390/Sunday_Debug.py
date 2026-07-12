def num_boats(weights, limit):

    weights.sort(reverse=True)

    left = len(weights) - 1      # Lightest soldier
    right = 0                    # Heaviest soldier
    boats = 0

    while right <= left:

        if weights[left] + weights[right] <= limit:
            left -= 1
            right += 1
        else:
            right += 1

        boats += 1

    print(boats)


weights = list(map(int, input().split()))
limit = int(input())

num_boats(weights, limit)
