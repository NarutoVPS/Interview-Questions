'''
    We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not. 
    All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing.

    More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exist an integer K, 1 <= K <= N such that,
    a1 <= a2 <= a3 .. <= aK >= a(K+1) >= a(K+2) …. >= aN

    Examples:
        Input : Arr[]  = [2 3 2 4 4 6 3 2], Range = [0, 2]
        Output :  Yes

        Explanation: The output is yes , subarray is [2 3 2], 
        so subarray first increases and then decreases

        Input:  Arr[] = [2 3 2 4 4 6 3 2], Range = [2, 7]
        Output: Yes

        Explanation: The output is yes , subarray is [2 4 4 6 3 2], 
        so subarray first increases and then decreases


        Input: Arr[]= [2 3 2 4 4 6 3 2], Range = [1, 3]
        Output: no

        Explanation: The output is no, subarray is [3 2 4], 
        so subarray is not in the form above stated
'''

def solve(arr):
    if len(arr) < 3:
        return 0

    current =  1
    maxPeak = 0
    while current < len(arr)-1:
        if arr[current] - arr[current-1] > 0 and arr[current] - arr[current+1] > 0:
            count, i = 1, current
            while i > 0 and arr[i] - arr[i-1] > 0:
                count += 1
                i -= 1

            i = current
            while i < len(arr)-1 and arr[i] - arr[i+1] > 0:
                count += 1
                i += 1 

            current = i

            maxPeak = max(maxPeak, count)

        else:
            current += 1
    return maxPeak
