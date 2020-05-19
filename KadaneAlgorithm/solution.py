def solve(arr):
    if not len(arr):
        return 0;
    if len(arr) == 1:
        return arr[0]

    maxSum = currentSum = arr[0]
    for each in arr[1:]:
        currentSum = max(currentSum + each, each)
        maxSum = max(currentSum, maxSum)

    return maxSum
