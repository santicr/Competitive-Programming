def binSearch(arr, x):
    low, high = 0, len(arr)

    while(low + 1 < high):
        mid = ((low + high) // 2)
        if(x < arr[mid]):
            high = mid
        else:
            low = mid
    return low

def climbingLeaderboard(ranked, player):
    pos = [1]
    rank = []
    res = []
    ranks = []

    for i in range(len(ranked)):
        if i >= 1:
            if(ranked[i] == ranked[i - 1]):
                pos.append(pos[i - 1])
            else:
                pos.append(pos[i - 1] + 1)
    i = len(ranked) - 1
    while i >= 0:
        rank.append(ranked[i])
        i -= 1

    for i in range(len(player)):
        res.append(binSearch(rank, player[i]))

    pos.reverse()
    for i in range(len(player)):
        p = res[i]
        if(rank[p] < player[i]):
            ranks.append(pos[p])
        elif rank[p] > player[i]:
            ranks.append(pos[p] + 1)
        elif rank[p] == player[i]:
            ranks.append(pos[p])

    print(pos)
    print(rank)
    print(player)
    print(res)
    print(ranks)

(climbingLeaderboard([100, 100, 50, 40, 40, 20, 10], [5, 25, 50, 120]))