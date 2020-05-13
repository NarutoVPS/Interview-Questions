'''
    An array is monotonic if it is either monotone increasing or monotone decreasing.

    An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

    Return true if and only if the given array A is monotonic.

        Example 1:
            Input: [1,2,2,3]
            Output: true

        Example 2:
            Input: [6,5,4,4]
            Output: true

        Example 3:
            Input: [1,3,2]
            Output: false

        Example 4:
            Input: [1,2,4,5]
            Output: true

        Example 5:
            Input: [1,1,1]
            Output: true
'''

# O(n) time | O(1) space
def solve(arr):
    if len(arr) < 3:
        return True
    direction = arr[1] - arr[0]
    for i in range(2, len(arr)):
        if direction == 0:
            direction = arr[i] - arr[i-1]
            continue
        if direction > 0:
            if arr[i] - arr[i-1] < 0:
                return False
        elif arr[i] - arr[i-1] > 0:
            return False
    return True



# O(n) time | O(1) space (much simpler version)
def solve2(arr):
    isIncreasing = True
    isDecreaing = True

    for i in range(1, len(arr)):
        if arr[i] - arr[i-1] > 0:
            isDecreaing = False
        elif  arr[i] - arr[i-1] < 0:
            isIncreasing = False

    return isIncreasing or isDecreaing
