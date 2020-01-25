def place(row, col, n, m):
    
    # Check above row of the same column
    for i in range(row, -1, -1):
        if m[i][col] == 1:
            return False

    # Check left upper diagonal
    for i, j in zip(range(row, -1, -1),
                    range(col, -1, -1)):
        if m[i][j]:
            return False
    
    # Check right upper diagonal
    for i, j in zip(range(row, -1, -1),
                    range(col, N)):
        if m[i][j]:
            return False

    return True


def nQueen(n, row, m):
    # print(row)
    if row >= n:
        # print("Entering print condition")
        for i in range(0, n):
            for j in range(0, n):
                print(m[i][j], end=" ")
            print()

        return True
    for i in range(0, n):
        if place(row, i, n, m):
            m[row][i] = 1
            if nQueen(n, row + 1, m) == True:
                return True
            m[row][i] = 0
    return False

board = [[0 for y in range(0, 11)] for x in range(0, 11)]
N = int(input())
if nQueen(N, 0, board) == False:
    print("No Solution Exist")
else:
    print("Solution")
