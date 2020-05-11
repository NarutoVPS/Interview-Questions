 
# Naive Approach--> O(n^2) time | O(1) space
# def solve(arr, target):
#     for i in range(len(arr)):
#         for j in range(i+1, len(arr)):
#             if arr[i] + arr[j] == target:
#                 return i,j
#     return None


#  Better Approach--> O(n) time | O(n) space
def solve(arr, target):
    available = dict()
    for i in range(len(arr)):
        currentNum = arr[i]
        if target-currentNum in available:
            return available[target-currentNum], i
        else:
            available[currentNum] = i
    return None

arr = [4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8]
print(solve(arr, -3))



# Given an array of integers, return indices of the two numbers such that they add up to a specific target.
# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# Example:
#     Given nums = [2, 7, 11, 15], target = 9,

#     Because nums[0] + nums[1] = 2 + 7 = 9,
#     return [0, 1].