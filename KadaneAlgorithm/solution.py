'''
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

    Example:
        Input: [-2,1,-3,4,-1,2,1,-5,4],
        Output: 6
        Explanation: [4,-1,2,1] has the largest sum = 6.
'''

def solve(arr):
    if not len(arr):
        return 0
    if len(arr) == 1:
        return arr[0]

    maxSum = currentSum = arr[0]
    for each in arr[1:]:
        currentSum = max(currentSum + each, each)
        maxSum = max(currentSum, maxSum)

    return maxSum
