def magicSquare(self, mat):
    #Your code here
    n = len(mat)
    M = n*(n**2+1)//2
    diag_sum = 0
    anti_diag_sum = 0
    for row in range(n):
        diag_sum += mat[row][row]
        anti_diag_sum += mat[n-row-1][row]
    if diag_sum != M :
        return 'Not a Magic Square'
    if anti_diag_sum != M:
        return 'Not a Magic Square'
    
    for row in range(n):
        row_sum = 0
        for col in range(n):
            row_sum += mat[row][col]
        if row_sum != M:
            return 'Not a Magic Square'
    
    for row in range(n):
        col_sum = 0
        for col in range(n):
            col_sum += mat[col][row]
        if col_sum != M:
            return 'Not a Magic Square'

    if sorted([item for row in mat for item in row]) != list(range(1,n*n+1)):
        return 'Not a Magic Square'
    return 'Magic Square'