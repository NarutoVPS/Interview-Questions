# Naive Approach--> O(n^3) time | O(1) space

# def solve(arr, target):
#     ans = []
#     for i in range(len(arr)):
#         for j in range(i+1, len(arr)):
#             for k in range(j+1, len(arr)):
#                 if arr[i]+arr[j]+arr[k] == target:
#                     ans.append([arr[i], arr[j], arr[k]])
#     return ans



# Better Approach O(n^2) time | O(n) space

def solve(arr, target):
    ans = []
    arr.sort()
    for i in range(len(arr)-2):
        currentNum = arr[i]
        left = i+1
        right = len(arr)-1
        while(left < right):
            currentSum = currentNum + arr[left] + arr[right]
            if currentSum == target:
                ans.append([currentNum, arr[left], arr[right]])
                left += 1
                right -= 1
            elif currentSum < target:
                left += 1
            else:
                right -= 1
    return ans

arr = [-1, 0, 1, 2, -2, -4]
print(solve(arr, 0))


# Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = target? 
# Find all unique triplets in the array which gives the sum of target.

# Given array nums = [-1, 0, 1, 2, -1, -4] and target = 0

#     A solution set is:
#     [
#         [-1, 0, 1],
#         [-1, -1, 2]
#     ]