# W -> weight of knapsack
# weights -> weight of each item
# value -> value of each item 
# Goal -> To maximize the value of items picked
def knapSackRec(weights, values, W,idx):
    if idx > len(values)-1:
        return 0
    pick = 0
    if weights[idx] <= W:
        pick = values[idx]+knapSackRec(weights, values, W, idx+1)
    not_pick = knapSackRec(weights, values, W, idx+1)
    return max(pick, not_pick)

weights = []
values = []
W = 9
knapSackRec()