# O(n) Time | O(d) Space (d -> depth of sub-array)
def solve(arr, multiplier = 1):
    sum = 0
    for each in arr:
        if type(each) is list:
            sum += solve(each, multiplier + 1)
        else:
            sum += each

    return sum * multiplier
