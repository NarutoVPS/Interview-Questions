'''
    Given an array of positive numbers, find the maximum sum of a subsequence with the constraint that no 2 numbers in the sequence should be adjacent in the array. 
    So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 3, 5 and 7).

    Examples :
        Input : arr[] = {5, 5, 10, 100, 10, 5}
        Output : 110

        Input : arr[] = {1, 2, 3}
        Output : 4

        Input : arr[] = {1, 20, 3}
        Output : 20
'''

# O(n) time | O(n) space
def solve(arr):
    if len(arr) == 0:
        return
    if len(arr) == 1:
        return arr[0]
    maxSum = arr[:]
    maxSum[1] = arr[0] if arr[0] > arr[1] else arr[1]
    for i in range(2, len(maxSum)):
        maxSum[i] = max(maxSum[i-1], maxSum[i-2]+maxSum[i])
    return maxSum[len(maxSum)-1]


