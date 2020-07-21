'''
    Given an array cantaining sub-array(s) upto say depth 'd', find the sum of all the elements of the array such that the sum of all elements of each sub-array is multiplied with its respective depth.

    Example :-
        Given array -> [1, 2, 3, [4, 5]]
        Product Sum = 24
'''

# O(n) Time | O(d) Space (d -> depth of sub-array)
def solve(arr, multiplier = 1):
    sum = 0
    for each in arr:
        if type(each) is list:
            sum += solve(each, multiplier + 1)
        else:
            sum += each

    return sum * multiplier
