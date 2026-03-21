def formingMagicSquare(s):
    # Write your code here
    magicSquares = [
        [[8,1,6],[3,5,7],[4,9,2]],
        [[4,3,8],[9,5,1],[2,7,6]],
        [[2,9,4],[7,5,3],[6,1,8]],
        [[6,7,2],[1,5,9],[8,3,4]],
        [[6,1,8],[7,5,3],[2,9,4]],
        [[2,7,6],[9,5,1],[4,3,8]],
        [[4,9,2],[3,5,7],[8,1,6]],
        [[8,3,4],[1,5,9],[6,7,2]]
    ]
    costs = []
    for i in range(8):
        currentCost = 0
        for j in range(3):
            for k in range(3):
                currentCost += abs(s[j][k] - magicSquares[i][j][k])
        costs.append(currentCost)
    return min(costs)
