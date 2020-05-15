'''
    Given a 2-dimensional array or a matrix, we have to traverse the given matrix in spiral order.

    Example 1:
        Input:
        [
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
        ]
        Output: [1,2,3,6,9,8,7,4,5]

    Example 2:
        Input:
        [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9,10,11,12]
        ]
        Output: [1,2,3,4,8,12,11,10,9,5,6,7]
'''

# O(n) time | O(n) space
def solve(arr):
    ans = []
    rowStart, rowEnd = 0, len(arr) - 1
    colStart, colEnd = 0, len(arr[0]) - 1

    while rowStart <= rowEnd and colStart <= colEnd:
        for i in range(colStart, colEnd + 1):
            ans.append(arr[rowStart][i])

        for i in range(rowStart + 1, rowEnd + 1):
            ans.append(arr[i][colEnd])

        for i in reversed(range(colStart, colEnd)):
            if rowStart == rowEnd:
                break
            ans.append(arr[rowEnd][i])

        for i in reversed(range(rowStart + 1, rowEnd)):
            if colStart == colEnd:
                break
            ans.append(arr[i][colStart])

        rowStart += 1
        rowEnd -= 1
        colStart += 1
        colEnd -= 1

    return ans
