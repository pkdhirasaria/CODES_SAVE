# Start Position is  (R,0) END POSITOIN IS : (0,C)
# Direction allowed : up and right
# find max cost while travelling from S to D.

def DP(matrix):
    row = len(matrix)
    col = len(matrix[0])

    for i in range(row - 2, -1, -1):
        matrix[i][0] += matrix[i + 1][0]

    for i in range(1, col):
        matrix[row-1][i] += matrix[row-1][i-1]
    # print(matrix)
    for i in range(row - 2, -1, -1):
        for j in range(1, col):
            matrix[i][j] += max(matrix[i][j-1], matrix[i+1][j])

    print(matrix[0][col-1])

M = []
for i in range(0, 3):
    M.append(list(map(int,input().split())))
DP(M)
