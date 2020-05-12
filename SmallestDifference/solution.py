# Naive Approach--> O(n^2) time | O(1) space

# def solve(arr1, arr2):
#     minDiff = float("inf")
#     minPair = []
#     for i in range(len(arr1)):
#         for j in range(len(arr2)):
#             if abs(arr1[i]-arr2[j]) < minDiff:
#                 minDiff = abs(arr1[i]-arr2[j])
#                 minPair = [arr1[i], arr2[j]]
#     return minPair


# Better Approach--> O(nlog(n) + mlog(m)) time | O(1) space where n,m are length of arr1 & arr2 respectively.

def solve(arr1, arr2):
    arr1.sort()
    arr2.sort()
    minDiff = float("inf")
    minPair = []
    i = 0
    j = 0

    while(i<len(arr1) and j<len(arr2)):
        if arr1[i] == arr2[j]:
            return [arr1[i], arr2[j]]
        else:
            if abs(arr1[i]-arr2[j]) < minDiff:
                minDiff = abs(arr1[i]-arr2[j])
                minPair = [arr1[i], arr2[j]]
            if arr1[i] < arr2[j]:
                i += 1
            else:
                j += 1
    return minPair

A = [1, 2, 11, 5]
B = [4, 12, 19, 23, 127, 235]

print(solve(A, B))




# Given two non-empty arrays of integers, find the pair of values (one value from each array) with the smallest (non-negative) difference.

# Example

#     Input: [1, 3, 15, 11, 2], [23, 127, 235, 19, 8]

#     Output: [11, 8]; this pair has the smallest difference.
