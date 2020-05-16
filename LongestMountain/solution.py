'''
    We are given an array of integers and a range, we need to find whether the subarray which falls in this range has values in the form of a mountain or not. 
    All values of the subarray are said to be in the form of a mountain if either all values are increasing or decreasing or first increasing and then decreasing.

    More formally a subarray [a1, a2, a3 … aN] is said to be in form of a mountain if there exist an integer K, 1 <= K <= N such that,
    a1 <= a2 <= a3 .. <= aK >= a(K+1) >= a(K+2) …. >= aN

    Example 1:
        Input: [2,1,4,7,3,2,5]
        Output: 5
        Explanation: The largest mountain is [1,4,7,3,2] which has length 5.

    Example 2:
        Input: [2,2,2]
        Output: 0
        Explanation: There is no mountain.
'''

# O(n) time | O(1) space
def solve(arr):
    # if the length of arr is less than 3, no peak/mountain exists
    if len(arr) < 3:
        return 0

    current, maxPeak =  1, 0

    # traverse through the array
    while current < len(arr)-1:
        # check if current element is a peak/mountain
        if arr[current] - arr[current-1] > 0 and arr[current] - arr[current+1] > 0:
            count, i = 1, current
            # count the elements that are decreasing at left side of the peak/mountain
            while i > 0 and arr[i] - arr[i-1] > 0:
                count += 1
                i -= 1

            i = current
            # count the elements that are decreasing at right side of the peak/mountain
            while i < len(arr)-1 and arr[i] - arr[i+1] > 0:
                count += 1
                i += 1 

            # continue traversing the array from the end of the current peak/mountain
            current = i

            # if the length of current peak/mountain is greater than maxPeak, update maxPeak
            maxPeak = max(maxPeak, count)

        else:
            current += 1
    return maxPeak
