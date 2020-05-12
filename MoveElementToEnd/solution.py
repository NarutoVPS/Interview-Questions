'''
    Given an array, move all occurances of a specified element "target" at the end of the array keeping the relative positon between the elements.
    You must do this in-place without making a copy of the array.

    Example:

        Input: [0,1,0,3,12]
        Output: [1,3,12,0,0]
'''

# O(n) time | O(1) space However this approach doesn't preserve relative position between elements

# def solve(arr, target):
#     i = 0
#     j = len(arr) - 1
#     while i < j:
#         while i < j and arr[j] == target:
#             j -= 1
#         if arr[i] == target:
#             arr[i], arr[j] = arr[j], arr[i]
#         i += 1




# O(n) time | O(1) space This approach preserves relative position between elements

def solve(arr, target):
    i = 0
    for current in range(len(arr)):
        if arr[current] != target:
            arr[i], arr[current] = arr[current], arr[i]
            i += 1

arr = [0,1,0,3,12]
solve(arr, 0)
print(arr)